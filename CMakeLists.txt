cmake_minimum_required(VERSION 3.8)
project(polkit-examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INSTALL_PREFIX /usr)

find_package(Qt5Core)
find_package(PolkitQt5-1)

add_subdirectory("demo1")
add_subdirectory("demo2")

install(FILES com.deepin.polkit.demo.policy
    DESTINATION /usr/share/polkit-1/actions/
)

# make uninstall
add_custom_target("uninstall" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall"
    POST_BUILD
    COMMENT "Uninstall files with install_manifest.txt"
    COMMAND xargs rm -vf < install_manifest.txt || echo Nothing in
            install_manifest.txt to be uninstalled!
)