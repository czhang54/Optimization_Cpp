# Optimization

This repository contains C++ codes for simulating global optimization algorithms. 
It is designed to be expandable so that one can add more:
  + Objective functions (src/Obj_fn.cpp)
  + Initialization methods for the optimizers (src/Prior.cpp)
  + Specific optimization algorithms (src/Algorithms/)

I am continuously working to make this project serve as a library for more general purposes. I will also add some more algorithms and objective functions.

A more comprehensive presentation of recent global optimization algorithms can be found in a technical note contained in the Optimization_Python project. 


Directories:
  + include: contains all the headers
  + src: contains all the source files
  + src/Algorithms: contains implementation of all optimization algorithms
  + example: contains example programs to do some simulation
 
Requirement:
  + Eigen: a convenient matrix library that can be downloaded at http://eigen.tuxfamily.org/index.php?title=Main_Page#Download
 
The project was tested on Mac OS 10.12 using g++ 4.2.1. 
To compile and run the demo (example.cpp) using command line: 
```
  cd example
  g++ -std=c++11 -I ./../include -c ./../src/*.cpp ./../src/Algorithms/*.cpp example.cpp
  g++ *.o -o example
  ./example
```

Alternatively, one can build/compile the project using the provided CMakeLists.txt:
```
  mkdir build
  cd build
  cmake -G "Unix Makefiles" .. 
  make 
  ./optimization 
```
Users may make substitutions (project names, CMake file type etc.) in the above command lines as appropriate

