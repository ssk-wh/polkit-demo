# 安装编译依赖
sudo apt install cmake qtbase5-dev libpolkit-qt5-1-dev

# 编译
cd polkit-demo
mkdir build
cd build
cmake ..
make -j8

# 运行
## 在运行前需要手动将此策略文件放到配置目录中，后面不需要再重复此目录，恢复时直接删除就好了
sudo cp com.deepin.polkit.demo.policy /usr/share/polkit-1/actions/

./polkit-demo

