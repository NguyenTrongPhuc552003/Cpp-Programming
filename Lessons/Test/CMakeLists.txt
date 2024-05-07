cmake_minimum_required(VERSION 3.24)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test main.cpp
        sources/Manager.cpp
        headers/Manager.h
        sources/Electronic.cpp
        headers/Electronic.h
        sources/Product.cpp
        headers/Product.h
        sources/Grocery.cpp
        headers/Grocery.h
        sources/Supermarket.cpp
        headers/Supermarket.h
        sources/Storage.cpp
        headers/Storage.h
        headers/Customer.h
        headers/Normal.h
        headers/Special.h
        sources/Customer.cpp
        sources/Invoice.cpp
        sources/Normal.cpp
        sources/Special.cpp)
