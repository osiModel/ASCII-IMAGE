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
    using dPair = pair<double,pair<uint16_t,uint16_t>>; 

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
void Calculate(const Map&, const Pos&, const Pos&);

#endif // VALUES_HPP
