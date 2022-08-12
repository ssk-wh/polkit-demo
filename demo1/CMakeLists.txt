project(polkit_demo)

set(SOURCE_FILES
        main.cpp)

add_executable(polkit_demo
    ${SOURCE_FILES})

target_link_libraries(polkit_demo
    Qt5::Core
    PolkitQt5-1::Agent)

install(TARGETS polkit_demo DESTINATION bin)
