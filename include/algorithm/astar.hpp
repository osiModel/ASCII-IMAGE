#ifndef VALUES_HPP
#define VALUES_HPP 

#include "alike/identical.hpp"
#include "data_structs.hpp"
#include <array>
#include <set>

namespace{
    using std::set;
    using std::array;
    using std::make_pair;
    using dPair = pair<double,pair<uint16_t,uint16_t>>; 
    using Details = vector<vector<Cell>>;
    //constexpr std::string_view CHARS = "BW"; - black and white
    //constexpr float DIV = 256/CHARS.size(); - for more types of colors
}

inline bool InRange(const Pos&, const Pos&);
inline bool IsWall(const Map&, const Pos&);
inline bool IsEnd(const Pos&, const Pos&);
inline double HValue(const Pos&, const Pos&);

void DirectionBlueprint(const array<Pos, 4>&, Details&,
                        bool&, set<dPair>&, const Map&, const Map&, 
                        double&, double&, double&);
void PrintPath(const Details&, const Pos&);

vector<Pos> Calculate(const Map&, const Pos&, const Pos&);
vector<Pos> Path(const Details&, const Pos&, const Pos&);

#endif // VALUES_HPP
