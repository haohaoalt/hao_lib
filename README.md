<!--
 * @Author: zhanghao
 * @Date: 2022-08-30 21:02:27
 * @LastEditTime: 2022-12-02 23:13:03
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
sudo ldconfig
```

Pangolin_example

<img src="README.assets/image-20221202231335963.png" alt="image-20221202231335963" style="zoom:50%;" />





## 03 Sophus

`fmt`
fmt库的安装
```
git clone  https://github.com/fmtlib/fmt.git # 注意要使用8或者7版本的，9的会报错，git checkout 7.1.3
git checkout -b 8.1.1
cd fmt
mkdir build
cd build 
cmake ..
make
sudo make install
```
Sophus李代数库的安装
```
git clone http://github.com/strasdat/Sophus.git
cd Sophus
mkdir build
cd build 
cmake ..
make
sudo make install
```

## 04 G2O
```
sudo apt-get install cmake libeigen3-dev libsuitesparse-dev qtdeclarative5-dev qt5-qmake libqglviewer-dev-qt5
git clone https://github.com/RainerKuemmerle/g2o.git
cd g2o
mkdir build
cd build
cmake ..
make
suao make install
```






安装依赖项
```
sudo apt-get install libglew-dev
sudo apt-get install libboost-dev libboost-thread-dev libboost-filesystem-dev
sudo apt-get install libpython2.7-dev
```
安装Pangolin

```
 git clone https://github.com/stevenlovegrove/Pangolin.git
 cd Pangolin
 mkdir build 
 cd build 
 cmake -DCPP11_NO_BOOSR=1 .. 
 make -j4
```

安装eigen3

```
sudo apt-get install libeigen3-dev
```

