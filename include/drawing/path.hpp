#ifndef PATH_HPP
#define PATH_HPP

#include "alike/identical.hpp"
#include <opencv2/opencv.hpp>
#include <string>

namespace {
    using std::string;
    using cv::Mat;
    using cv::Vec3b;
    using cv::imwrite;
    using GreyMap = vector<vector<uint8_t>>;
    const Vec3b COLOR = {255, 0 , 0};
    const string SAVE_PATH = "../result/IMAGE.png";
}

class Painter{
public:
    Painter() = default;
    Painter(const string&);

    void DrawPath(const Mat&, const vector<Pos>&);

    void SetPixelSize(const uint16_t& pixelSize){
        m_pixelSize = pixelSize;
    }
private:
    void SaveImg(const cv::Mat& image, const string& path){
        imwrite(path, image);
    }

    string m_savePath = SAVE_PATH;
    uint16_t m_pixelSize = 1; 
};

#endif // PATH_HPP
