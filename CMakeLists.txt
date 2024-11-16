cmake_minimum_required(VERSION 3.28)

project(PathFinder)

set(CXX_STANDARD_REQUIRED 11)
set(SOURCES
    main.cpp
    src/astar.cpp
    src/path.cpp
    src/path_finder.cpp)

find_package(OpenCV REQUIRED)

add_executable(PathFinder ${SOURCES})

target_include_directories(PathFinder PRIVATE include)
target_include_directories(PathFinder PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(PathFinder ${OpenCV_LIBS})
