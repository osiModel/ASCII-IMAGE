#ifndef PATH_HPP
#define PATH_HPP

#include "alike/identical.hpp"
#include <opencv2/opencv.hpp>
#include <string>

namespace {
    using std::string;
    using GreyMap = vector<vector<uint8_t>>;
    const cv::Vec3b COLOR = {255, 0 , 0};
    const string PATH = "../result/IMAGE.png";
}

inline void SaveImg(const cv::Mat&, const string&);

void DrawPath(const cv::Mat&, const vector<Pos>&);

uint16_t CheckSize(const GreyMap&, const Pos&); 

#endif // PATH_HPP
