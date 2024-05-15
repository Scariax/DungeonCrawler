cmake_minimum_required(VERSION 3.5)

project(New_DungeonCrawler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(New_DungeonCrawler main.cpp
    tile.h tile.cpp
    floor.h floor.cpp
    wall.h wall.cpp
    portal.h portal.cpp
    character.h character.cpp
    level.h level.cpp
    dungeoncrawler.h dungeoncrawler.cpp
    abstractui.h abstractui.cpp
    terminalui.h terminalui.cpp)

include(GNUInstallDirs)
install(TARGETS New_DungeonCrawler
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
