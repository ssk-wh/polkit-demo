project(demo2)

find_package(Qt5Widgets)
find_package(Qt5DBus)

#-------------Server------------------
set(SOURCE_SERVER_FILES
        server/main.cpp
        server/dbus_manager.cpp
        server/dbus_manager.h)

add_executable(polkit_server ${SOURCE_SERVER_FILES})

target_link_libraries(polkit_server
    Qt5::Widgets
    Qt5::DBus
    PolkitQt5-1::Agent)

install(TARGETS polkit_server DESTINATION bin)

install(FILES server/com.deepin.dde.pokit.demo.conf
    DESTINATION /etc/dbus-1/system.d/
)

install(FILES server/com.deepin.dde.pokit.demo.service
    DESTINATION /lib/systemd/system/
)

#-------------Client------------------
set(SOURCE_CLIENT_FILES
        client/main.cpp)

add_executable(polkit_client ${SOURCE_CLIENT_FILES})

target_link_libraries(polkit_client Qt5::Widgets Qt5::DBus)

install(TARGETS polkit_client DESTINATION bin)
