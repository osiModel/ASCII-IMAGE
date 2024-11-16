#ifndef PATH_FINDER_HPP
#define PATH_FINDER_HPP

#include "algorithm/astar.hpp"
#include "drawing/path.hpp"

class PathFinder{
public:
    PathFinder() = default;
    PathFinder(const string&, const string& savePath = SAVE_PATH);

    void SetImagePath(const string&);
    void SetSavePath(const string&);
    void SetDiagonal(const bool& diagonal){
        m_diagonal = diagonal;
    }

    uint16_t GetWidth(){
        return m_map.empty() ? 0 : m_map[0].size();
    }
    uint16_t GetHeight(){
        return m_map.size();
    }

    void FindPath();
    void DrawPath();
private:
    void FillUp();
    bool IsValid(const Pos&);
    
    AStar maze;
    Painter painting;

    uint16_t m_pixelSize = 1;
    string m_savePath = SAVE_PATH;
    string m_imagePath;
    Mat m_image;
    Mat m_greyImage;
    Pos m_start{INT16_MAX, INT16_MAX};
    Pos m_end{INT16_MAX, INT16_MAX};
    vector<Pos> m_path;
    Map m_map;
    GreyMap m_greyMap;
    bool m_diagonal = false;

    bool isFinded = false;
    bool isFilled = false;

    bool isValid(const Pos&);
};

#endif // PATH_FINDER_HPP
