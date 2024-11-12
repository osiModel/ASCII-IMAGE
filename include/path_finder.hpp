#ifndef PATH_FINDER_HPP
#define PATH_FINDER_HPP

#include "algorithm/astar.hpp"
#include "drawing/path.hpp"

namespace{
    using cv::Mat;
    using std::string;
}

class PathFinder{
public:
    PathFinder() = default;
    PathFinder(const Mat&);
    PathFinder(const string&);

    void FindPath();
    void DrawPath();
private:
    AStar maze;
    Painter painting;

    string m_imagePath;
    Mat m_image;
    Mat m_greyImage;
    Pos m_start{INT16_MAX, INT16_MAX};
    Pos m_end{INT16_MAX, INT16_MAX};
    vector<Pos> m_path;
    Map m_map;
    GreyMap m_greyMap;

    bool isFinded = false;
};

#endif // PATH_FINDER_HPP
