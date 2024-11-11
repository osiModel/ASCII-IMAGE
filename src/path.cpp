#include "drawing/path.hpp"

inline bool IsIncreasing(const Pos& range, const Pos& dot){
    uint32_t y = dot.first;
    uint32_t x = dot.second;
    
    return !(y >= range.first || x >= range.second);
}

inline bool IsValid(const GreyMap& map,const Pos& dot){
    uint32_t y = dot.first;
    uint32_t x = dot.second;

    return(map[y][x] >= 40 || map[y][x] <= 180);
}

uint16_t CheckSize(const GreyMap& map, const Pos& dot){
    uint16_t size = 1;
    uint16_t y = dot.first;
    uint16_t x = dot.second;
    Pos range = {map.size(), map[0].size()};


    while(IsValid(map, {y+size,x+size}) && IsIncreasing(range, {y+size,x+size})){
        ++size;
    }

    return size;
}

inline void SaveImg(const cv::Mat& image, const string& path){
    cv::imwrite(path, image);
}

void DrawPath(const cv::Mat& imageReference, const vector<Pos>& mazePath){   
    cv::Mat image = imageReference.clone();

    for(const auto& cord : mazePath){
                    image.at<cv::Vec3b>(cord.first, cord.second) = COLOR;
    }
    
    SaveImg(image, PATH);
}
