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

class Painter{
public:
    void DrawPath(const cv::Mat&, const vector<Pos>&);
private:
    inline void SaveImg(const cv::Mat&, const string&);
};

#endif // PATH_HPP
