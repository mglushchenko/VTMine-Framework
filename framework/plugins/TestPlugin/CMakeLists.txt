cmake_minimum_required(VERSION 3.5)

project(TestPlugin LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_library(TestPlugin SHARED
  TestPlugin_global.h
  testplugin.cpp
  testplugin.h
)

#target_link_libraries(TestPlugin PRIVATE Qt5::Core)
target_link_libraries(TestPlugin Qt5::Widgets)

target_compile_definitions(TestPlugin PRIVATE TESTPLUGIN_LIBRARY)
