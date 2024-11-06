#include "drawing/path.hpp"

namespace {
    const cv::Vec3b COLOR = {255, 0 , 0};
    const string PATH = "../result/IMAGE.png";
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