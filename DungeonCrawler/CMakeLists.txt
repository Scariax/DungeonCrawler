cmake_minimum_required(VERSION 3.27)
project(DungeonCrawler)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonCrawler main.cpp
        Character.h
        Character.cpp
        Tile.h
        Tile.cpp
        Floor.h
        Floor.cpp
        Wall.h
        Wall.cpp
        Portal.h
        Portal.cpp
        level.h level.cpp
        abstractui.h abstractui.cpp
        terminalui.h terminalui.cpp
        dungeoncrawler.h dungeoncrawler.cpp)
