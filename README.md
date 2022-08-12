# 安装编译依赖
sudo apt install cmake qtbase5-dev libpolkit-qt5-1-dev

# 编译
cd polkit-demo
mkdir build
cd build
cmake ..
make -j8
make install

# 也可以选择打包安装，这样更方便
dpkg-buildpackage -us -uc -nc

# 安装
sudo dpkg -i [deb path]

# 运行
运行服务端
systemctl start com.deepin.dde.pokit.demo.service

运行客户端，通过dbus调用实现提权操作，完成普通进程无法处理的操作
/usr/bin/polkit_client

