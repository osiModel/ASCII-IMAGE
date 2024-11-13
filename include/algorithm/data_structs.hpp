#ifndef DATA_STRUCTS_HPP
#define DATA_STRUCTS_HPP

#include <vector>
#include <cstdint>

namespace{
    using std::vector;

    struct Cell{
        uint16_t yParent{}, xParent{};
        double f{},g{},h{}; 
    };

    vector<vector<int8_t>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},
                                        {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
        
    using Details = vector<vector<Cell>>;
}

#endif // DATA_STRUCTS_HPP
