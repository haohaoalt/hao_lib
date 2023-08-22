/*
 * @Author: https://github.com/haohaoalt
 * @Date: 2023-08-22 09:50:18
 * @LastEditors: haohaoalt haohaoalt@163.com
 * @LastEditTime: 2023-08-22 09:53:18
 * @FilePath: /hao_lib/pcl_example/kd_tree/kd_tree_demo.cpp
 * @Description: 
 * Copyright (c) 2023 by haohaoalt@163.com, All Rights Reserved. 
 */
#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

#include <iostream>
#include <vector>
#include <ctime>

int main()
{
    srand(time(NULL)); // 随机种子
                       // [1] 创建点云指针
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    // [2] 生成一千个无序点云数据
    // Generate pointcloud data
    cloud->width = 1000;
    cloud->height = 1;
    cloud->points.resize(cloud->width * cloud->height);

    for (std::size_t i = 0; i < cloud->size(); ++i)
    {
        (*cloud)[i].x = 1024.0f * rand() / (RAND_MAX + 1.0f);
        (*cloud)[i].y = 1024.0f * rand() / (RAND_MAX + 1.0f);
        (*cloud)[i].z = 1024.0f * rand() / (RAND_MAX + 1.0f);
    }

    // [3]创建KD-Tre对象
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    // [4]向KDTREE中传入数据，即将点云数据设置成KD-Tree结构
    kdtree.setInputCloud(cloud);
    // [5]随机生成一个点
    pcl::PointXYZ searchPoint;

    searchPoint.x = 1024.0f * rand() / (RAND_MAX + 1.0f);
    searchPoint.y = 1024.0f * rand() / (RAND_MAX + 1.0f);
    searchPoint.z = 1024.0f * rand() / (RAND_MAX + 1.0f);

    int K = 10;
    // [6]K近邻搜索，即搜索该点周围的10个点
    std::vector<int> pointIdxKNNSearch(K);
    // [7]设置搜索距离为10
    std::vector<float> pointKNNSquaredDistance(K);

    std::cout << "K nearest neighbor search at (" << searchPoint.x
              << " " << searchPoint.y
              << " " << searchPoint.z
              << ") with K=" << K << std::endl;
    // 开始K近邻搜索
    if (kdtree.nearestKSearch(searchPoint, K, pointIdxKNNSearch, pointKNNSquaredDistance) > 0)
    {
        for (std::size_t i = 0; i < pointIdxKNNSearch.size(); ++i)
            std::cout << "    " << (*cloud)[pointIdxKNNSearch[i]].x
                      << " " << (*cloud)[pointIdxKNNSearch[i]].y
                      << " " << (*cloud)[pointIdxKNNSearch[i]].z
                      << " (squared distance: " << pointKNNSquaredDistance[i] << ")" << std::endl;
    }

    // Neighbors within radius search
    // 使用半径搜索条件搜索
    std::vector<int> pointIdxRadiusSearch;
    std::vector<float> pointRadiusSquaredDistance;
    // 随机生成一个搜索半径
    float radius = 256.0f * rand() / (RAND_MAX + 1.0f);
    std::cout << "Neighbors within radius search at (" << searchPoint.x
              << " " << searchPoint.y
              << " " << searchPoint.z
              << ") with radius=" << radius << std::endl;

    // 开始半径搜索
    if (kdtree.radiusSearch(searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0)
    {
        for (std::size_t i = 0; i < pointIdxRadiusSearch.size(); ++i)
            std::cout << "    " << (*cloud)[pointIdxRadiusSearch[i]].x
                      << " " << (*cloud)[pointIdxRadiusSearch[i]].y
                      << " " << (*cloud)[pointIdxRadiusSearch[i]].z
                      << " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
    }

    return 0;
}
