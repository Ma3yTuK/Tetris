cmake_minimum_required(VERSION 3.16)

project(Tetris VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appTetris
    main.cpp
    src/game/TetrisLayout.cpp
    src/game/shapes/NotActiveShape.cpp
    src/game/shapes/figures/TetrisFigureShape.cpp
    src/game/Game.cpp
)

qt_add_qml_module(appTetris
    URI Tetris
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appTetris PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTetris
    PRIVATE Qt6::Quick
)

target_include_directories(appTetris
    PRIVATE include
)

install(TARGETS appTetris
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
