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
    //constexpr std::string_view CHARS = "BW"; - black and white
    //constexpr float DIV = 256/CHARS.size(); - for more types of colors
}



bool NextStep(const Map& ,const Pos&);

vector<Pos> Calculate(const vector<vector<Pixel>>& ,int32_t& ,const vector<uint16_t>&);

#endif // VALUES_HPP
