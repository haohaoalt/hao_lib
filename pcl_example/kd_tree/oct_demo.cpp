/*
 * @Author: https://github.com/haohaoalt
 * @Date: 2023-08-22 10:29:23
 * @LastEditors: haohaoalt haohaoalt@163.com
 * @LastEditTime: 2023-08-22 10:35:06
 * @FilePath: /hao_lib/pcl_example/kd_tree/oct_demo.cpp
 * @Description: 
 * Copyright (c) 2023 by haohaoalt@163.com, All Rights Reserved. 
 */
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
// #include <pcl/io/openni_grabber.h>
#include <pcl/io/openni2_grabber.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/compression/octree_pointcloud_compression.h>

#include <stdio.h>
#include <sstream>
#include <stdlib.h>

#ifdef WIN32
#define sleep(x) Sleep((x)*1000)
#endif

class SimpleOpenNIViewer
{
public:
    SimpleOpenNIViewer() : viewer(" Point Cloud Compression Example")
    {
    }

    // 在OpenNIGrabber捕获循环执行的回调函数中(以下部分代码)，首先将捕获的点云压缩到stringstream缓冲区中。接下来是一个解压步骤，该步骤将压缩的二进制数据解码为一个新的点云对象。然后将解码后的点云发送到点云查看器。
    void
    cloud_cb_(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
    {
        if (!viewer.wasStopped())
        {
            // 存储被压缩后点云的流
            std::stringstream compressedData;
            // 创建输出的解压缩后点云指针
            pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloudOut(new pcl::PointCloud<pcl::PointXYZRGBA>());
            // 压缩点云
            PointCloudEncoder->encodePointCloud(cloud, compressedData);

            // 解压缩点云
            PointCloudDecoder->decodePointCloud(compressedData, cloudOut);

            // 显示解压缩后的点云
            viewer.showCloud(cloudOut);
        }
    }

    void
    run()
    {
        // 布尔值：是否显示统计信息（是）
        bool showStatistics = true;

        // 配置文件列表查看这个头文件: /io/include/pcl/compression/compression_profiles.h
        // 此处是枚举类型，包括压缩配置(分辨率，在/离线，颜色信息)
        pcl::io::compression_Profiles_e compressionProfile = pcl::io::MED_RES_ONLINE_COMPRESSION_WITH_COLOR;
        // 实例化八叉树点云压缩用于编码和解码
        PointCloudEncoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>(compressionProfile, showStatistics);
        PointCloudDecoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>();

        // 创建OpenNI设备的抓取器
        // pcl::Grabber *interface = new pcl::OpenNIGrabber();
        pcl::Grabber *interface = new pcl::io::OpenNIGrabber();

        // 定义回调函数，用于回调点云采集设备
        std::function<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &)> f =
            [this](const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
        { cloud_cb_(cloud); };

        // 注册链接回调函数.此例子中是带有颜色信息的点云。
        boost::signals2::connection c = interface->registerCallback(f);

        // 开始接收点云，
        interface->start();

        while (!viewer.wasStopped())
        {
            sleep(1);
        }

        interface->stop();

        // 删除点云压缩实例
        delete (PointCloudEncoder);
        delete (PointCloudDecoder);
    }

    pcl::visualization::CloudViewer viewer;

    pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> *PointCloudEncoder;
    pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> *PointCloudDecoder;
};

int main()
{
    SimpleOpenNIViewer v;
    v.run();

    return (0);
}
