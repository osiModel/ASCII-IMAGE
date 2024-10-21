#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string_view>

namespace{
    using Pixel = uint8_t; 
    constexpr std::string_view CHARS = "BW"; // characters that used in map proc
    constexpr float DIV = 256/CHARS.size(); /* var used to know
                                             what type of char we
                                                 need to use */
}

int main()
{
    bool flag = 0;
    cv::Mat image; // image
    image = cv::imread("../images/maze_1.png",cv::IMREAD_GRAYSCALE); // reading with only one chanel
    std::vector<std::vector<Pixel>> map(image.cols,std::vector<Pixel>(image.rows));
    // used for string every pixel on the image

    for(int i = 0;i<image.cols;++i){
        for(int j = 0;j<image.rows;++j){
            map[i][j] = static_cast<int>(image.at<Pixel>(i,j)/DIV);
        }
        std::cout<<std::endl;
    }   // fill up our map

    std::cout<<"PATH IS FINDED!\n";

    return 0;
}

