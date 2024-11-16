#include "pf/path_finder.hpp"

int main(int argc,char** argv){
    string path = "/home/admin/Desktop/c++/projects/Path_Finder/images/testlargemaze_2.png"; 

    if(argc == 2){
        path = argv[1];
    }

    PathFinder pf;
    pf.SetImagePath(path);
    pf.SetSavePath("../result/IMAGE.png");
    pf.FindPath();
    pf.DrawPath();
}
