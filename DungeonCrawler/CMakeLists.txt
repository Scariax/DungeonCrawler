cmake_minimum_required(VERSION 3.5)

project(Test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Test main.cpp
    Tile.cpp
    Wall.h Wall.cpp Tile.h Tile.cpp terminalui.h terminalui.cpp Portal.h Portal.cpp main.cpp level.h level.cpp Floor.h Floor.cpp dungeoncrawler.h dungeoncrawler.cpp Character.h Character.cpp abstractui.h abstractui.cpp)

include(GNUInstallDirs)
install(TARGETS Test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
