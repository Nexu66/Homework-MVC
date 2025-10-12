cmake_minimum_required(VERSION 3.15)
project(PatternMVC CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Format)
FORMAT_DIR(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source)


add_subdirectory(source)