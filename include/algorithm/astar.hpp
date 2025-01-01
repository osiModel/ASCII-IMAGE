#ifndef ASTAR_HPP
#define ASTAR_HPP 

#include "alike/identical.hpp"
#include "data_structs.hpp"
#include <array>
#include <set>
#include <cmath>

namespace{
    using Details = vector<vector<Cell>>;
    using dPair = pair<double,pair<uint16_t,uint16_t>>; 
    using std::array;
    using std::set;
    using std::pow;
    using std::sqrt;
}

class AStar{    
public:
    AStar() = default;
    vector<Pos> Calculate(const Map&, const Pos&, const Pos&, const bool& diagonal = false);
private:
    bool InRange(const Pos& pos, const Pos& range){
        return ((pos.first <= range.first) && (pos.second <= range.second) && (pos.second >= 0) && (pos.first >= 0));
    }
    bool IsWall(const Map& map, const Pos& pos){
        return (map[pos.first][pos.second] == 0);
    }
    bool IsEnd(const Pos& start, const Pos& end){
        return (start == end);
    }
    double HValue(const Pos& pos, const Pos& end){
        return  (sqrt(pow((end.first - pos.first),2) + pow((end.second - pos.second),2)));  
    }

    vector<Pos> Path(const Details&, const Pos&, const Pos&);
};  

#endif // ASTAR_HPP
