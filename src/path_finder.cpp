#include "pf/path_finder.hpp"
#include <iostream>

namespace{
    using cv::imread;
    using std::cout;
    using std::cerr;
    using cv::IMREAD_GRAYSCALE;
}

bool PathFinder::isValid(const Pos& pos){
    uint16_t yRange = m_greyMap.size();
    uint16_t xRange = m_greyMap[0].size();  
    uint16_t y = pos.first;
    uint16_t x = pos.second;

    if(yRange <= y || xRange <= x)
        return false;

    uint8_t greyShade = m_greyMap[y][x]; 
    return (greyShade >= 40 && greyShade <= 180);
}

void PathFinder::FillUp(){
    m_image = imread(m_imagePath);
    m_greyImage = imread(m_imagePath,IMREAD_GRAYSCALE);
    m_map = Map(m_image.cols,vector<Pixel>(m_image.rows));
    m_greyMap = GreyMap(m_greyImage.cols,vector<uint8_t>(m_greyImage.rows));

    for(uint16_t i = 0;i<m_greyImage.cols;++i){
        for(uint16_t j = 0;j<m_greyImage.rows;++j){
            uint8_t greyShade = m_greyImage.at<uint8_t>(i,j);
            m_map[i][j] = (greyShade >= 180);
            m_greyMap[i][j] = greyShade;
            if(greyShade >= 40 && greyShade <= 180){
                    if(m_start.first == INT16_MAX){
                        m_start = {i,j};
                    } else {
                        m_end = {i,j};
                    }
                    m_map[i][j] = 1;
            }
        }
    }

    uint16_t x = m_start.second;
    uint16_t y = m_start.first;   

    while(isValid({++y,++x})){
        ++m_pixelSize;
    }

    if(m_pixelSize == 1) return;

    if(m_image.cols % m_pixelSize == 0){
        y = m_image.cols / m_pixelSize;
        x = m_image.rows / m_pixelSize;
        m_map = Map(y,vector<Pixel>(x));
        m_greyMap = GreyMap(y,vector<uint8_t>(x));
        m_start = {INT16_MAX, INT16_MAX};
        m_end = {INT16_MAX, INT16_MAX};

        uint16_t i{};
        uint16_t j{};
        uint16_t realI{1};
        uint16_t realJ{1};
        for(realI = 1,i = 0;i<y;realI+=m_pixelSize,++i){
            for(realJ = 1,j = 0;j<x;realJ+=m_pixelSize,++j){
                uint8_t greyShade = m_greyImage.at<uint8_t>(realI-1,realJ-1);
                m_map[i][j] = (greyShade >= 180);
                m_greyMap[i][j] = greyShade;
                if(greyShade >= 40 && greyShade <= 180){
                        if(m_start.first == INT16_MAX){
                            m_start = {i,j};
                        } else {
                            m_end = {i,j};
                        }
                        m_map[i][j] = 1;
                }
            }
        }
    }else{
        cerr<<"size of start point must be a multiple of image size\n";
        isFilled = false;
    }

}

PathFinder::PathFinder(const string& imagePath, const string& savePath) : m_imagePath(imagePath), painting(savePath){
    isFilled = true;
}

void PathFinder::SetImagePath(const string& imagePath){
    m_imagePath = imagePath;
    isFilled = true;
}

void PathFinder::SetSavePath(const string& savePath){
    m_savePath = savePath;
    if(!m_imagePath.empty())
        isFilled = true;
} 

void PathFinder::FindPath(){
    if(isFilled){
        FillUp();
        m_path = maze.Calculate(m_map,m_start,m_end,m_diagonal);
        if(!m_path.empty()){
            isFinded = true;
            cout<<"Path is finded\n";
        }else{
            cout<<"Failed to find path\n";
        }
    }else{
        cerr<<"First write image path\n";
    }
}

void PathFinder::DrawPath(){
    painting.SetPixelSize(m_pixelSize);
    if(isFinded){
        painting.DrawPath(m_image,m_path);
        cout<<"Image is saved to: "<<m_savePath<<"\n";
    }else{
        cerr<<"First call FindPath method\n";
    }
}   
