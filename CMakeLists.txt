cmake_minimum_required(VERSION 3.8)
project(polkit-examples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(PolkitQt5-1)

add_subdirectory("demo1")
add_subdirectory("demo2")

install(FILES com.deepin.polkit.demo.policy
    DESTINATION /usr/share/polkit-1/actions/
)
