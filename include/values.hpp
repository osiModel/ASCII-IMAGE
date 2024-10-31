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
        int yParent{}, xParent{};
        double f{},g{},h{}; 
    };


    using std::set;
    using std::pair; 
    using std::array;
    using std::vector;
    using Pixel = bool;
    using Pos = pair<int,int>; 
    using Map = vector<vector<Pixel>>;
    using Details = vector<vector<Cell>>;
    using crPos = const Pos&;
    using dPair = pair<double,pair<int,int>>; 

    //constexpr std::string_view CHARS = "BW"; - black and white
    //constexpr float DIV = 256/CHARS.size(); - for more types of colors
}

inline bool InRange(crPos, crPos);
inline bool IsWall(const Map&, crPos);
inline bool IsEnd(crPos, crPos);
inline double HValue(crPos, crPos);


void DirectionBlueprint(const array<Pos, 4>&, Details&,
                        bool&, set<dPair>&, const Map&, const Map&, 
                        double&, double&, double&);
void PrintPath(const Details&, crPos);
void Calculate(const Map&, crPos, crPos);

#endif // VALUES_HPP
