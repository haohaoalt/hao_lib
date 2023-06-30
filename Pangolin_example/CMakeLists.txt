cmake_minimum_required(VERSION 3.10)
# Find Pangolin (https://github.com/stevenlovegrove/Pangolin)
project(Pangolin_demo)
find_package(Pangolin REQUIRED)
MESSAGE(STATUS "Pangolin version: "${Pangolin_VERSION})
MESSAGE(STATUS "PROJECT_SOURCE_DIR: "${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "PROJECT_BINARY_DIR: "${PROJECT_BINARY_DIR})
MESSAGE(STATUS "Pangolin_INCLUDE_DIRS: "${Pangolin_INCLUDE_DIRS})
MESSAGE(STATUS "Pangolin_LIBRARIES: "${Pangolin_LIBRARIES})


include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(HelloPangolin main.cpp)
target_link_libraries(HelloPangolin ${Pangolin_LIBRARIES})