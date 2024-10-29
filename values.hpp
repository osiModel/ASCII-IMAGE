#ifndef VALUES_HPP
#define VALUES_HPP 

#include <cstdint>
//#include <string_view>
#include <vector>
#include <utility>


namespace{
    using std::pair; 
    using std::vector;
    using Pixel = bool;
    using Pos = pair<uint16_t,uint16_t>; 
    using Map = vector<vector<Pixel>>;
    using Details = vector<vector<Cell>>;
    using crint = const uint16_t&;
    using crpos = const Pos&;

    struct Cell{
        uint16_t yParent{}, xParent{};
        double f{},g{},h{}; 
    };
    //constexpr std::string_view CHARS = "BW"; - black and white
    //constexpr float DIV = 256/CHARS.size(); - for more types of colors
}

inline bool InRange(crpos, crpos);
inline bool IsWall(const Map&, crpos);
inline bool IsEnd(crpos, crpos);
inline double HValue(crint, crint, crpos);

void DirectionBlueprint(crpos, const Details&);
void PrintPath(const Details&, crpos);
void Calculate(const Map&, crpos, crpos);

#endif // VALUES_HPP
