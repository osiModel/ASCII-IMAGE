#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "values.hpp"

int main()
{
    bool flag = 0;
    cv::Mat image; // image
    int32_t simplestPath{};
    image = cv::imread("../images/maze_1.png",cv::IMREAD_GRAYSCALE); // reading with only one chanel
    vector<vector<Pixel>> map(image.cols,std::vector<Pixel>(image.rows));
    // used for store every pixel on the image

    for(int i = 0;i<image.cols;++i){
        for(int j = 0;j<image.rows;++j){
            map[i][j] = static_cast<int>(image.at<Pixel>(i,j)/DIV);
        }
        std::cout<<std::endl;
    }   // fill up our map


    std::cout<<"PATH IS FINDED!\n";
    for(const auto& i : Calculate(map, simplestPath)){
        std::cout<<i.first<<"-x "<<i.second<<"-y\n";
    }
    std::cout<<"Size of path is: "<<simplestPath<<std::endl;

    return EXIT_SUCCESS;
}

