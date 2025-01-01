#include "algorithm/astar.hpp"
#include <cmath>
#include <stack>
#include <cfloat>
#include <iostream>

namespace{
    using std::cout;
    using std::cerr;
    using std::stack;
    using std::make_pair;
}

void PrintPath(const Details& detail, const Pos& end){
    uint16_t Y = end.first;
    uint16_t X = end.second;
    stack<Pos> path;
    cout<<"PATH IS FINDED: ";

    while(!(detail[Y][X].xParent == X && detail[Y][X].yParent == Y)){
        path.push({Y,X});
        uint16_t tempX = detail[Y][X].xParent;
        uint16_t tempY = detail[Y][X].yParent;
        Y = tempY;
        X = tempX;

    } 
    path.push({Y,X});
    
    while(!path.empty()){
        Pos p = path.top();
        path.pop();
        cout<<"-> "<<p.second+1<<"-x "<<p.first+1<<"-y ";
    }
    cout<<"\n";
}

vector<Pos> AStar::Path(const Details& details, const Pos& start, const Pos& end){
    vector<Pos> path;
    uint16_t X = end.second;
    uint16_t Y = end.first;

    while(!(details[Y][X].xParent == X 
        && details[Y][X].yParent == Y)){
            uint16_t tempY = details[Y][X].yParent;
            uint16_t tempX = details[Y][X].xParent;
            X = tempX;
            Y = tempY;

            if(!(Y == start.first && X == start.second))
                path.push_back({Y,X});
    }

    return path;
}

vector<Pos> AStar::Calculate(const Map& map, 
const Pos& start, const Pos& end, const bool& diagonal){
    Pos range = {map.size()-1,map[0].size()-1}; 
    if(!InRange(start,range)){
        std::cerr<<"Invalid start coords!";
        return vector<Pos>();
    }

    if(!InRange(end,range)){
        std::cerr<<"Invalid end coords!";
        return vector<Pos>();;
    }

    if(IsWall(map, start) || IsWall(map, end)){
        std::cerr<<"Start or end is blocked!";
        return vector<Pos>();;
    }

    if(IsEnd(start,end)){
        cout<<"Start is already at the destination!\n";
        return vector<Pos>();
    }

    Map closedList(range.first+1, vector<Pixel>(range.second+1,false));
    Details details(range.first+1, vector<Cell>(range.second+1));

    for(uint16_t i = 0;i<=range.first;++i){
        for(uint16_t j = 0;j<=range.second;++j){
            details[i][j].f = DBL_MAX;
            details[i][j].g = DBL_MAX;
            details[i][j].h = DBL_MAX;
            details[i][j].xParent = UINT16_MAX;
            details[i][j].yParent = UINT16_MAX;
        }
    }

    uint16_t y = start.first;
    uint16_t x = start.second;
    details[y][x].f = 0.0;
    details[y][x].g = 0.0;
    details[y][x].h = 0.0;
    details[y][x].xParent = x;
    details[y][x].yParent = y;

    set<dPair> openList;
    openList.insert({0.0,{y,x}});
    bool founded = false;

    vector<vector<int8_t>> directions(DIRECTIONS.begin(), DIRECTIONS.begin()+4);
    if(diagonal)    
        directions = DIRECTIONS;

    while(!openList.empty() && !founded){
        dPair dp = *openList.begin();
        openList.erase(openList.begin());
        double gNew{},hNew{},fNew{};
        y = dp.second.first;
        x = dp.second.second;
        closedList[y][x] = true;

        for(const auto& dir : directions){
            uint16_t newY = dir[0] + y;
            uint16_t newX = dir[1] + x;
            const Pos posNew = {newY,newX}; 
            const Pos posCurr = {y,x};

            if(dir[0] + y >= 0 && dir[1] + x >= 0){
                if(InRange(posNew, range)){
                    uint16_t y = posNew.first;
                    uint16_t x = posNew.second;
                    uint16_t prevY = posCurr.first;
                    uint16_t prevX = posCurr.second;
                    if(IsEnd(posNew, end)){
                        details[y][x].xParent = prevX;
                        details[y][x].yParent = prevY;  
                        /*
                        PrintPath(details, end);
                        */
                        founded = true;
                        break;
                    }else if(!closedList[y][x] && !IsWall(map, posNew)){
                        gNew = details[prevY][prevX].g + 1.414f;
                        hNew = HValue(posNew, end);
                        fNew = gNew + hNew;
                        if(details[y][x].f == DBL_MAX || details[y][x].f > fNew){
                            openList.insert({fNew,{y,x}});
                            details[y][x].g = gNew;
                            details[y][x].h = hNew;
                            details[y][x].f = fNew;
                            details[y][x].xParent = prevX;
                            details[y][x].yParent = prevY;
                        }
                    }
                }
            }
        }
    }    
    //PrintPath(details,end); <- if you want to print path to console
    if (!founded){
       cerr<<"Failed to find the Destination Cell\n";
       return vector<Pos>();
    }

    return Path(details,start,end);
}
