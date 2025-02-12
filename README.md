### Build Instructions

This repository consists of exercises containing algorithm and data structure examples.
Exercises are based on 'Mastering Data Structures & Algorithms using C and C++', Created by 
Abdul Bari.

Resources::
* https://www.udemy.com/course/datastructurescncpp/

**Disclaimer**: I do not have any relation with the original author of the course or the course it self.

### Build Instructions

Prerequisite is to have g++ with the c++20 standard installed and CMake with minum version 3.15.

Build standalone examples (without cmake) with the following command:
```
g++ -std=c++20 -o <exercise_name>.exe exercises/<exercise_name>.cpp
```

Build cmake examples with the following commands:
```
cd <module_folder>\<example_folder>
mkdir build 
cd build
cmake ..
```
