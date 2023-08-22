cmake_minimum_required(VERSION 3.10)

project(pcl_demo)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_demo kd_tree_demo.cpp)
target_link_libraries(pcl_demo ${PCL_LIBRARIES})
