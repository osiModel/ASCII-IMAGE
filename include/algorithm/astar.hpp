#ifndef VALUES_HPP
#define VALUES_HPP 

#include "alike/identical.hpp"
#include "data_structs.hpp"

namespace{
    using Details = vector<vector<Cell>>;
}

/*
THESE FUNCS ARE NOT IMPLEMENTATION, SO I DON'T NEED THEM HERE

inline bool InRange(const Pos&, const Pos&);
inline bool IsWall(const Map&, const Pos&);
inline bool IsEnd(const Pos&, const Pos&);
inline double HValue(const Pos&, const Pos&);

void DirectionBlueprint(const array<Pos, 4>&, Details&,
                        bool&, set<dPair>&, const Map&, const Map&, 
                        double&, double&, double&);
*/

void PrintPath(const Details&, const Pos&);

vector<Pos> Calculate(const Map&, const Pos&, const Pos&, const bool& diagonal = false);
vector<Pos> Path(const Details&, const Pos&, const Pos&);

#endif // VALUES_HPP
