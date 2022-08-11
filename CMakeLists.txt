cmake_minimum_required(VERSION 3.8)
project(polkit-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(PolkitQt5-1)

set(SOURCE_FILES
        main.cpp)

add_executable(polkit-demo
    ${SOURCE_FILES})

target_link_libraries(polkit-demo
    Qt5::Core
    PolkitQt5-1::Agent)
