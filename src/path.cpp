#include "drawing/path.hpp"

inline void Painter::SaveImg(const cv::Mat& image, const string& path){
    cv::imwrite(path, image);
}

void Painter::DrawPath(const cv::Mat& imageReference, const vector<Pos>& mazePath){   
    cv::Mat image = imageReference.clone();

    for(const auto& cord : mazePath){
                    image.at<cv::Vec3b>(cord.first, cord.second) = COLOR;
    }
    
    SaveImg(image, PATH);
}
