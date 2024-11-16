# Path_Finder
## **The tool that finds the shortest path in the maze using opencv and A* (astar) algorithm.**

## How it works?
Using opencv it scans every pixel on the image and draws path on image. 
Using A* (astar) algorithm it finds the shortest math.

### **Example:**
![IMAGE](https://github.com/user-attachments/assets/9925c626-6610-4a75-8ff8-8216442f4a33)

### How to make it? 
First of all you need to set image path.You can do it by calling member function:
```
PathFinder pf;
pf.SetImagePath("path/to/img.png");
```

Or as argument in the constructor:
```
PathFinder pf("path/to/img.png");
```

After that you need to call 2 member functions **FindPath()** and **DrawPath()**.
Image will be saved to the default save path if you don't set one.

## Additional:
1. To get the height and length call **GetWidht()** and **GetHeight()** accordingly.
2. To set diagonal movement call **SetDiagonal()** method.
3. To set image and save path call **SetImagePath()** and **SetSavePath()** respectively.  

To run the project (in terminal):
```
mkdir build
cd build
cmake --build .
./PathFinder 
```

### To use this project you need:
  1. C++11
  2. opencv
  3. CMake 3.28


  
