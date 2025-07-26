cmake_minimum_required(VERSION 3.19)
project(Lesson2HomeWork LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)
find_package(Qt6 6.5 REQUIRED COMPONENTS Network)

qt_standard_project_setup()

qt_add_executable(Lesson2HomeWork
    main.cpp
)

target_link_libraries(Lesson2HomeWork
    PRIVATE
        Qt::Core
)

target_link_libraries(Lesson2HomeWork PRIVATE Qt6::Network)

include(GNUInstallDirs)

install(TARGETS Lesson2HomeWork
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
