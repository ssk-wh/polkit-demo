# 0、安装编译依赖
sudo apt install build-essential cmake qtbase5-dev libpolkit-qt5-1-dev

# 1、编译
cd polkit-demo
mkdir build
cd build
cmake ..
make -j8
sudo make install

# 2、也可以选择早debian文件夹所在的目录打包安装，这样更方便
dpkg-buildpackage -us -uc -nc

## 2.1、安装打包生成的deb包(生成的deb包在上一目录中)
sudo dpkg -i [deb path]

# 3、运行
运行服务端
systemctl start com.deepin.dde.pokit.demo.service

运行客户端，通过dbus调用实现提权操作，完成普通进程无法处理的操作
/usr/bin/polkit_client

# 4、恢复电脑环境
sudo make uninstall

