cmake_minimum_required(VERSION 3.25)
project(Employee_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Employee_Manager main.cpp headers/Storage.h
        sources/Employee.cpp
        sources/Resume.cpp
        sources/Storage.cpp
        sources/Resume.cpp
        sources/Timekeeping.cpp
        headers/DaysoffMonth.h
        sources/DaysoffMonth.cpp)
