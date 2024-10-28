#ifndef VALUES_HPP
#define VALUES_HPP 

#include <cstdint>
//#include <string_view>
#include <vector>
#include <utility>
#include <array>

namespace{
    using std::pair; 
    using std::array;
    using std::vector;
    using Pixel = bool;
    using Pos = pair<uint16_t,uint16_t>; 
    using Map = vector<vector<Pixel>>;
    using crint = const int32_t&;
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


vector<Pos> Calculate(const Map& ,size_t& ,const array<Pos, 2>&);

#endif // VALUES_HPP
