#ifndef ASTAR_HPP
#define ASTAR_HPP 

#include "alike/identical.hpp"
#include "data_structs.hpp"
#include <array>
#include <set>

namespace{
    using Details = vector<vector<Cell>>;
    using dPair = pair<double,pair<uint16_t,uint16_t>>; 
    using std::array;
    using std::set;
}

class AStar{
public:
    AStar() = default;

    void PrintPath(const Details&, const Pos&);
    vector<Pos> Calculate(const Map&, const Pos&, const Pos&, const bool& diagonal = false);

private:
    inline bool InRange(const Pos&, const Pos&);
    inline bool IsWall(const Map&, const Pos&);
    inline bool IsEnd(const Pos&, const Pos&);
    inline double HValue(const Pos&, const Pos&);

    vector<Pos> Path(const Details&, const Pos&, const Pos&);
    void DirectionBlueprint(const array<Pos, 4>&, 
                        Details&, 
                        bool& founded, 
                        set<dPair>&, 
                        const Map&,
                        const Map&,
                        double&,
                        double&,
                        double&);
};  

#endif // ASTAR_HPP
