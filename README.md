# README

一个用于 polkit 提权验证的demo项目，如果您不清楚如何在项目中发起此类请求或不清楚如何使用 polkit，demo1 和 demo2 对您会有所帮助

## 安装编译依赖
`sudo apt install build-essential cmake qtbase5-dev libpolkit-qt5-1-dev`

## 编译
``` bash
cd polkit-demo
mkdir build
cd build
cmake ..
make -j8
sudo make install
```

## 也可以选择在 debian 文件夹所在的目录打包安装，这样更方便
`dpkg-buildpackage -us -uc -nc`

### 安装打包生成的 deb 包(生成的 deb 包在上一目录中)
`sudo dpkg -i [deb path]`

## 运行
运行服务端
`systemctl start com.deepin.dde.pokit.demo.service`

运行客户端，通过 dbus 调用实现提权操作，完成普通进程无法处理的操作
`/usr/bin/polkit_client`

## 恢复电脑环境
`sudo make uninstall`或者`sudo apt remove polkit-example`

