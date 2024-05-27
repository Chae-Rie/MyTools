cmake_minimum_required(VERSION 3.14)

project(MyTools LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MyTools STATIC
  mytools.cpp
  mytools.h
)

target_compile_definitions(MyTools PRIVATE MYTOOLS_LIBRARY)
