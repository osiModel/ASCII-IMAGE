#include "values.hpp"
#include <cmath>
#include <stack>
#include <cfloat>
#include <iostream>


namespace{
    using std::cout;
    using std::stack;
    using std::pow;
    using std::sqrt;
    using std::make_pair;
    vector<vector<int8_t>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
}


inline bool InRange(const Pos& pos, const Pos& range){
    return ((pos.first <= range.first) && (pos.second <= range.second) && (pos.second >= 0) && (pos.first >= 0));
}



inline bool IsWall(const Map& map, const Pos& pos){
    return map[pos.first][pos.second] == 0;
}

inline bool IsEnd(const Pos& start, const Pos& end){
    return start == end;
}

inline double HValue(const Pos& pos, const Pos& end){
    return  sqrt(pow((end.first - pos.first),2) + pow((end.second - pos.second),2));  
}

void PrintPath(const Details& detail, const Pos& end){
    uint16_t endY = end.first;
    uint16_t endX = end.second;
    stack<Pos> path;
    cout<<"PATH IS FINDED: ";
    while(!(detail[endY][endX].xParent == endX && detail[endY][endX].yParent == endY)){
        path.push({endY,endX});
        uint16_t tempX = detail[endY][endX].xParent;
        uint16_t tempY = detail[endY][endX].yParent;
        endY = tempY;
        endX = tempX;
    } 
    path.push({endY,endX});
    while(!path.empty()){
        Pos p = path.top();
        path.pop();
        cout<<"-> "<<p.second+1<<"-x "<<p.first+1<<"-y ";
    }
    cout<<"\n";
}

void DirectionBlueprint(const array<Pos, 4>& positions, 
                        Details& details, 
                        bool& founded, 
                        set<dPair>& openList, 
                        const Map& closedList,
                        const Map& map,
                        double& g,
                        double& h,
                        double& f){
    if(InRange(positions[0], positions[2])){
        uint16_t y = positions[0].first;
        uint16_t x = positions[0].second;
        uint16_t prevY = positions[3].first;
        uint16_t prevX = positions[3].second;
        if(IsEnd(positions[0], positions[1])){
            details[y][x].xParent = prevX;
            details[y][x].yParent = prevY;  
            PrintPath(details, positions[1]);
            founded = true;
            return;

        }else if(!closedList[y][x] && !IsWall(map, positions[0])){
            g = details[prevY][prevX].g + 1.414;
            h = HValue(positions[0], positions[1]);
            f = g + h;

            if(details[y][x].f == DBL_MAX || details[y][x].f > f){
                openList.insert({f,{y,x}});
                details[y][x].g = g;
                details[y][x].h = h;
                details[y][x].f = f;
                details[y][x].xParent = prevX;
                details[y][x].yParent = prevY;
            }
        }
    }
}

void Calculate(const Map& map, 
const Pos& start, const Pos& end){
    Pos range = {map.size()-1,map[0].size()-1}; 
    cout<<range.first<<" "<<range.second<<std::endl;
    if(!InRange(start,range)){
        std::cerr<<"Invalid start coords!";
        return;
    }

    if(!InRange(end,range)){
        std::cerr<<"Invalid end coords!";
        return;
    }

    if(IsWall(map, start) || IsWall(map, end)){
        std::cerr<<"Start or end is blocked!";
        return;
    }

    if(IsEnd(start,end)){
        cout<<"Start is already at the destination!\n";
    }

    Map closedList(range.first+1, vector<Pixel>(range.second+1,false));
    Details details(range.first+1, vector<Cell>(range.second+1));

    for(size_t i = 0;i<=range.first;++i){
        for(size_t j = 0;j<=range.second;++j){
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

    while(!openList.empty()){
        dPair dp = *openList.begin();
        openList.erase(openList.begin());

        y = dp.second.first;
        x = dp.second.second;
        closedList[y][x] = true;

        double gNew{},hNew{},fNew{};
        for(const auto& dir : DIRECTIONS){
            uint16_t newY = dir[0] + y;
            uint16_t newX = dir[1] + x;
            if(dir[0] + y >= 0 && dir[1] + x >= 0){
                DirectionBlueprint({make_pair(newY, newX),end,range,make_pair(y,x)},details,founded,openList,closedList,map,gNew,hNew,fNew);
            }
        }
        if(founded)
            return;
    }
    if (founded == false)
        cout<<"Failed to find the Destination Cell\n";
}
