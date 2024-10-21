cmake_minimum_required(VERSION 3.28)

project(test)

set(CXX_STANDARD_REQUIRED 17)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable( test main.cpp )

target_link_libraries( test ${OpenCV_LIBS})
