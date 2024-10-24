#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "values.hpp"

int main()
{
    cv::Mat image; 
    vector<Pos> enter; 
    int32_t simplestPath{};
    image = cv::imread("../images/testmaze_1.png",cv::IMREAD_GRAYSCALE); 
    vector<vector<Pixel>> map(image.cols,std::vector<Pixel>(image.rows));

    for(int i = 0;i<image.cols;++i){
        for(int j = 0;j<image.rows;++j){
            map[i][j] = (image.at<uint8_t>(i,j) <= 128);
            if((i == 0 || i == image.cols-1 || 
                j == 0 || j == image.rows-1) && !map[i][j]){
                    enter.push_back({i,j});           
            }
        }
    }   

    if(enter.size() < 2){
        std::cerr<<"LESS THEN TWO ENTERS";
        return EXIT_FAILURE;
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

