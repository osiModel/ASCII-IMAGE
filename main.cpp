#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "values.hpp"

int main()
{
    cv::Mat image; 
    Pos start {-1, -1};
    Pos end {-1, -1}; 
    int32_t simplestPath{};
    image = cv::imread("../images/color_1.png",cv::IMREAD_GRAYSCALE); 
    Map map(image.cols, vector<Pixel>(image.rows));

    for(int32_t i = 0;i<image.cols;++i){
        for(int32_t j = 0;j<image.rows;++j){
            uint8_t greyPixel = image.at<uint8_t>(i,j);
            map[i][j] = (greyPixel >= 180);
            std::cout<<map[i][j]<<" ";
            if((i == 0 || i == image.cols-1 || 
                j == 0 || j == image.rows-1) && map[i][j] >= 40 && map[i][j] <= 180){
                    if(start.first == -1){
                        start = {i,j};
                    } else {
                        end = {i,j};
                    }
            }
        }
        std::cout<<std::endl;
    }

    /*
    std::cout<<"PATH IS FINDED!\n";
    for(const auto& i : Calculate(map, simplestPath)){
        std::cout<<i.first<<"-x "<<i.second<<"-y\n";
    }
    std::cout<<"Size of path is: "<<simplestPath<<std::endl;
    */

    return EXIT_SUCCESS;
}

