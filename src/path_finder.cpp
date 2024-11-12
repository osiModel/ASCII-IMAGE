#include "path_finder.hpp"
#include <iostream>

namespace{
    using cv::imread;
    using std::cout;
    using cv::IMREAD_GRAYSCALE;
}

PathFinder::PathFinder(const string& path) : m_imagePath(path){
    m_image = imread(m_imagePath);
    m_greyImage = imread(m_imagePath,IMREAD_GRAYSCALE);
    m_map = Map(m_image.cols,vector<Pixel>(m_image.rows));
    m_greyMap = GreyMap(m_greyImage.cols,vector<uint8_t>(m_greyImage.rows));

    for(size_t i = 0;i<m_greyImage.cols;++i){
        for(size_t j = 0;j<m_greyImage.rows;++j){
            uint8_t greyPixel = m_greyImage.at<uint8_t>(i,j);
            m_map[i][j] = (greyPixel >= 180);
            m_greyMap[i][j] = greyPixel;
            if(greyPixel >= 40 && greyPixel <= 180){
                    if(m_start.first == INT16_MAX){
                        m_start = {i,j};
                    } else {
                        m_end = {i,j};
                    }
                    m_map[i][j] = 1;
            }
        }
    }
}

void PathFinder::FindPath(){
    isFinded = true;
    m_path = maze.Calculate(m_map,m_start,m_end);
}

void PathFinder::DrawPath(){
    if(isFinded){
        painting.DrawPath(m_image,m_path);
    }else{
        cout<<"First call FindPath method!\n";
    }
}   
