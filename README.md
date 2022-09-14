<!--
 * @Author: zhanghao
 * @Date: 2022-08-30 21:02:27
 * @LastEditTime: 2022-09-14 23:27:22
 * @FilePath: /hao_lib/README.md
 * @Description: 安装各种库的集合
-->
# hao_lib
自己安装各种库的集合
# 01 opencv
```
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
```
```
cd opencv
git checkout -b 4.6.0
cd opencv_contrib
git checkout -b 4.6.0  
```
```
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev libopenexr-dev \
    libgstreamer-plugins-base1.0-dev libgstreamer1.0-dev
```
```
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/home/hao007/haolib/opencv4.6/install -D OPENCV_EXTRA_MODULES_PATH=/home/hao007/haolib/opencv4.6/opencv_contrib/modules ~/haolib/opencv4.6/opencv ..
```

```
make
sudo make install
```
## 02 Panglin
```
git clone https://github.com/stevenlovegrove/Pangolin.git
sudo apt install libglew-dev
cd Pangolin
mkdir build
cd build
cmake ..
make
sudo make install
```
