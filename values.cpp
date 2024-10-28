#include "values.hpp"
#include <cmath>

inline bool InRange(crpos pos, crpos range){
    return ((pos.first < range.first) && (pos.second < range.second) && (pos.second >= 0) && (pos.first >= 0));
}

inline bool IsWall(const Map& map, const Pos& pos){
    return map[pos.first][pos.second] == 1;
}

inline bool IsEnd(crpos start, crpos end){
    return start == end;
}

double HValue(crpos pos, crpos end){
    return  sqrt(pow((pos.first - end.first),2) + pow((pos.second - end.second),2));  
}


vector<Pos> Calculate(const Map& map, 
size_t& simplestPath, 
const array<Pos,2>& enter){
    vector<Pos> result;





    simplestPath = result.size();
    return result;            
}
