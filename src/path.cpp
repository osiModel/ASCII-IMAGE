#include "drawing/path.hpp"

Painter::Painter(const string& savePath) : m_savePath(savePath){}

void Painter::DrawPath(const cv::Mat& imageReference, const vector<Pos>& mazePath){   
    cv::Mat image = imageReference.clone();
    if(m_pixelSize == 1){
        for(const auto& cord : mazePath){
            image.at<cv::Vec3b>(cord.first, cord.second) = COLOR;
        }
    }else{
        for(const auto& cord : mazePath){
            uint16_t x = m_pixelSize * cord.second;
            uint16_t y = m_pixelSize * cord.first;
            for(uint16_t i = y;i<y+m_pixelSize;++i){
                for(uint16_t j = x;j<x+m_pixelSize;++j){
                    image.at<cv::Vec3b>(i, j) = COLOR;
                }
            }
        }
    }
    SaveImg(image, SAVE_PATH);
}
