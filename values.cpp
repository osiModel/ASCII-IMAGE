#include "values.hpp"
#include <cmath>
#include <stack>
#include <set>
#include <cfloat>
#include <iostream>

namespace{
    using std::set;
    using std::cout;
    using std::stack;
    using dpair = pair<double,pair<uint16_t,uint16_t>>; 
}


inline bool InRange(crpos pos, crpos range){
    return ((pos.first < range.first) && (pos.second < range.second) && (pos.second >= 0) && (pos.first >= 0));
}

void DirectionBlueprint(crpos distance, const Details&){
    
}

inline bool IsWall(const Map& map, const Pos& pos){
    return map[pos.first][pos.second] == 1;
}

inline bool IsEnd(crpos start, crpos end){
    return start == end;
}

double HValue(crpos pos, crpos end){
    return  sqrt(pow((end.first - pos.first),2) + pow((end.second - pos.second),2));  
}

void PrintPath(const vector<vector<Cell>>& detail, crpos end){
    int32_t endY = end.first;
    int32_t endX = end.second;
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
crpos start, crpos end){
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

    vector<vector<bool>> closedList(range.first+1, vector<bool>(range.second+1));
    vector<vector<Cell>> details(range.first+1, vector<Cell>(range.second+1));

    for(int i = 0;i<=range.first;++i){
        for(int j = 0;j<=range.second;++j){
            details[i][j].f = DBL_MAX;
            details[i][j].g = DBL_MAX;
            details[i][j].h = DBL_MAX;
            details[i][j].xParent = UINT16_MAX;
            details[i][j].yParent = UINT16_MAX;
        }
    }

    int y = start.first;
    int x = start.second;
    details[y][x].f = 0.0;
    details[y][x].g = 0.0;
    details[y][x].h = 0.0;
    details[y][x].xParent = x;
    details[y][x].yParent = y;

    set<dpair> openList;
    openList.insert({0.0,{y,x}});

    bool finded = false;

    while(!openList.empty()){
        dpair dp = *openList.begin();
        openList.erase(openList.begin());

        y = dp.second.first;
        x = dp.second.second;
        closedList[y][x] = true;

        double gNew{},hNew{},fNew{};


    }
}
