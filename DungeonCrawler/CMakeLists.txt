cmake_minimum_required(VERSION 3.27)
project(Dungeoncrawler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dungeoncrawler
    abstractview.cpp
        abstractview.h
        active.cpp
        active.h
        character.cpp
        character.h
        dungeoncrawler.cpp
        dungeoncrawler.h
        floor.cpp
        floor.h
        level.cpp
        level.h
        main.cpp
        passive.cpp
        passive.h
        portal.cpp
        portal.h
        terminalui.cpp
        terminalui.h
        tile.cpp
        tile.h
        wall.cpp
        wall.h
        switch.h switch.cpp
        door.h door.cpp
        pit.h pit.cpp
        ramp.h ramp.cpp
        abstractcontroller.h abstractcontroller.cpp)
