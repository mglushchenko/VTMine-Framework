cmake_minimum_required(VERSION 3.0)

# Basic information about project

project(VTMine VERSION 1.0)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(VTMine main.cpp)
target_link_libraries(VTMine Qt5::Widgets)

add_subdirectory(core)



#qt5_use_modules(vtmine Widgets)  # уточнить, должен ли быть здесь первым параметров target, а не имя проекта!
