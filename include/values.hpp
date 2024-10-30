#ifndef VALUES_HPP
#define VALUES_HPP 

#include <cstdint>
//#include <string_view>
#include <vector>
#include <utility>
#include <array>
#include <set>

namespace{
    struct Cell{
        uint16_t yParent{}, xParent{};
        double f{},g{},h{}; 
    };


    using std::set;
    using std::pair; 
    using std::array;
    using std::vector;
    using Pixel = bool;
    using Pos = pair<uint16_t,uint16_t>; 
    using Map = vector<vector<Pixel>>;
    using Details = vector<vector<Cell>>;
    using crint = const uint16_t&;
    using crPos = const Pos&;
    using dPair = pair<double,pair<uint16_t,uint16_t>>; 

    //constexpr std::string_view CHARS = "BW"; - black and white
    //constexpr float DIV = 256/CHARS.size(); - for more types of colors
}

inline bool InRange(crPos, crPos);
inline bool IsWall(const Map&, crPos);
inline bool IsEnd(crPos, crPos);
inline double HValue(crint, crint, crPos);


void DirectionBlueprint(const array<Pos, 3>&, Details&, bool&, set<dPair>&,
                        const Map&, const Map&, const array<double&, 3>&);
void PrintPath(const Details&, crPos);
void Calculate(const Map&, crPos, crPos);

#endif // VALUES_HPP
