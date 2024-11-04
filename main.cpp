#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "algorithm/values.hpp"
#include <iostream>
#include <vector>
#include <cstdint>
#include <stack>

int main(int argc, char** argv){
    if(argc != 2){
        std::cerr<<"Enter the img path!\n";
        return EXIT_FAILURE;
    }

    cv::Mat image; 
    bool status = false;
    Pos start {INT16_MAX, INT16_MAX};
    Pos end {INT16_MAX, INT16_MAX}; 
    image = cv::imread(argv[1],cv::IMREAD_GRAYSCALE); 
    Map map(image.cols, std::vector<Pixel>(image.rows));
    
    for(int16_t i = 0;i<image.cols;++i){
        for(int16_t j = 0;j<image.rows;++j){
            uint8_t greyPixel = image.at<uint8_t>(i,j);
            map[i][j] = (greyPixel >= 180);
            if(greyPixel >= 40 && greyPixel <= 180){
                    if(start.first == INT16_MAX){
                        start = {i,j};
                    } else {
                        end = {i,j};
                        status = true;
                    }
                    map[i][j] = 1;
            }
            std::cout<<map[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    if(status){
        Calculate(map,start,end);
    }

    return EXIT_SUCCESS;
}
