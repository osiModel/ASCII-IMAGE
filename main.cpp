#include "path_finder.hpp"

namespace {
    const std::string IMAGE_PATH = "../images/testmaze_5.png";
}


int main(int argc, char** argv){ 
    std::string imagePath = IMAGE_PATH;

    if(argc == 2){
        imagePath = argv[1];
    }

    PathFinder pf(IMAGE_PATH);
    pf.DrawPath();
    pf.FindPath();
    pf.DrawPath();
}
