#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "algorithm/astar.hpp"
#include "drawing/path.hpp"
#include <iostream>
#include <vector>
#include <cstdint>
#include <string> 

int main(int argc, char** argv){ 
    std::string imagePath = "../images/testmaze_5.png";
    bool defaultPath = true;

    if(argc == 2){
        imagePath = argv[1];
        defaultPath = false;
    }

    cv::Mat image = cv::imread(imagePath);
    cv::Mat greyImage = cv::imread(imagePath,cv::IMREAD_GRAYSCALE); 
    std::vector<Pos> path;
    bool status = false;
    Pos start {INT16_MAX, INT16_MAX};
    Pos end {INT16_MAX, INT16_MAX}; 
    Map map(greyImage.cols, std::vector<Pixel>(greyImage.rows));
    GreyMap greyMap(greyImage.cols, std::vector<uint8_t>(greyImage.rows));

    for(size_t i = 0;i<greyImage.cols;++i){
        for(size_t j = 0;j<greyImage.rows;++j){
            uint8_t greyPixel = greyImage.at<uint8_t>(i,j);
            map[i][j] = (greyPixel >= 180);
            greyMap[i][j] = greyPixel;
            if(greyPixel >= 40 && greyPixel <= 180){
                    if(start.first == INT16_MAX){
                        start = {i,j};
                    } else {
                        end = {i,j};
                        status = true;
                    }
                    map[i][j] = 1;
            }
        }
    }
    uint16_t offset = CheckSize(greyMap,start);

    start.first += offset - 1;
    start.second += offset - 1;

    if(status){
        path = Calculate(map,start,end);
        
        uint16_t size = CheckSize(greyMap,start);
        std::cout<<size;
        DrawPath(image,path,size);
    } 

    return EXIT_SUCCESS;
}
