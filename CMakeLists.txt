cmake_minimum_required(VERSION 3.28)

project(test)

set(CXX_STANDARD_REQUIRED 11)
set(SOURCES
    main.cpp
    src/astar.cpp
    src/path.cpp)

find_package(OpenCV REQUIRED)

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(test ${SOURCES})

target_link_libraries( test ${OpenCV_LIBS})
