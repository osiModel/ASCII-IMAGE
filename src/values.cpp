#include "../include/values.hpp"
#include <cmath>
#include <stack>
#include <cfloat>
#include <iostream>


namespace{
    using std::cout;
    using std::stack;
    constexpr array<array<int8_t, 2>, 8> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
}


inline bool InRange(crPos pos, crPos range){
    return ((pos.first < range.first) && (pos.second < range.second) && (pos.second >= 0) && (pos.first >= 0));
}

void DirectionBlueprint(const array<Pos, 3>& positions, 
                        Details& details, 
                        bool& finded, 
                        set<dPair>& openList, 
                        const Map& closedList,
                        const Map& map,
                        const array<double&, 3>& GHF){
    if(InRange(positions[0], positions[2])){
        uint16_t y = positions[0].first;
        uint16_t x = positions[0].second;

        if(IsEnd(positions[0], positions[2])){
            details[y][x].xParent = x;
            details[y][x].yParent = y;  
            PrintPath(details, positions[1]);
            finded = true;
            return;

        }else if(!closedList[y][x] && !IsWall(map, positions[0])){
            GHF[0] = details[y][x].g + 1.0;
            GHF[1] = HValue(positions[0], positions[1]);
            GHF[2] = GHF[0] + GHF[1];

            if(details[y][x].f == DBL_MAX || details[y][x].f > GHF[2]){
                openList.insert({GHF[2],{y,x}});
                details[y][x].g = GHF[0];
                details[y][x].h = GHF[1];
                details[y][x].f = GHF[2];
                details[y][x].xParent = x;
                details[y][x].yParent = y;
            }
        }
    }
}


inline bool IsWall(const Map& map, const Pos& pos){
    return map[pos.first][pos.second] == 1;
}

inline bool IsEnd(crPos start, crPos end){
    return start == end;
}

double HValue(crPos pos, crPos end){
    return  sqrt(pow((end.first - pos.first),2) + pow((end.second - pos.second),2));  
}

void PrintPath(const Details& detail, crPos end){
    uint16_t endY = end.first;
    uint16_t endX = end.second;
    stack<Pos> path;

    while(!(detail[endY][endX].xParent == endX && detail[endY][endX].yParent == endY)){
        path.push({endY,endX});
        endX = detail[endY][endX].xParent;
        endY = detail[endY][endX].yParent;
    } 
    path.push({endY,endX});
    while(!path.empty()){
        Pos p = path.top();
        path.pop();
        cout<<"-> "<<p.second<<"-x "<<p.first<<"-y ";
    }
}

void Calculate(const Map& map, 
crPos start, crPos end){
    Pos range = {map.size()-1,map[0].size()-1}; 

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
        std::cout<<"Start is already at the destination!\n";
    }

    Map closedList(range.first+1, vector<bool>(range.second+1));
    Details details(range.first+1, vector<Cell>(range.second+1));

    for(int i = 0;i<=range.first;++i){
        for(int j = 0;j<=range.second;++j){
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

    bool finded = false;

    while(!openList.empty()){
        dPair dp = *openList.begin();
        openList.erase(openList.begin());

        y = dp.second.first;
        x = dp.second.second;
        closedList[y][x] = true;

        double gNew{},hNew{},fNew{};
        for(const auto& dir : DIRECTIONS){
            int newY = dir[0] + y;
            int newX = dir[1] + x;

            DirectionBlueprint({std::make_pair(newY, newX),end,range},details,finded,openList,closedList,map,{gNew,hNew,fNew});
        }
    }
}
