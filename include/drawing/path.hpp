#ifndef PATH_HPP
#define PATH_HPP

#include "alike/identical.hpp"
#include <opencv2/opencv.hpp>
#include <string>

namespace {
    using std::string;
}

inline void SaveImg(const cv::Mat&, const string&);

void DrawPath(const cv::Mat&, const vector<Pos>&);

uint16_t CheckSize(const Pos&, const Map&); // todo

#endif // PATH_HPP