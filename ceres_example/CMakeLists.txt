cmake_minimum_required(VERSION 3.10)
project(ceres)

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

find_package(OpenCV REQUIRED) 
# 将OpenCV库的头文件路径添加到include路径中
include_directories(${OpenCV_INCLUDE_DIRS})
MESSAGE(STATUS "OpenCV version: ${OpenCV_VERSION}")

add_executable(min_value min_value.cpp)
target_link_libraries(min_value ${CERES_LIBRARIES})

add_executable(curve_fitting curve_fitting.cpp)
target_link_libraries(curve_fitting ${CERES_LIBRARIES} ${OpenCV_LIBS})