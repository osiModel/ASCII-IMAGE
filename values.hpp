#ifndef VALUES_HPP
#define VALUES_HPP 

#include <cstdint>
#include <string_view>
#include <vector>
#include <utility>

namespace{
    using Pixel = uint8_t;
    using std::vector;
    using std::pair; 
    constexpr std::string_view CHARS = "BW";    
    constexpr float DIV = 256/CHARS.size(); 
}

vector<pair<int16_t,int16_t>> Calculate(const vector<vector<Pixel>>& , const int32_t&);

#endif // VALUES_HPP