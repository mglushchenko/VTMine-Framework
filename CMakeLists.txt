cmake_minimum_required(VERSION 3.0)

# Basic information about project

project(vtmine VERSION 1.0)


set(SOURCE_FILES
    src/main.cpp
    src/IFramework.h
    src/MainWorker.h
    src/MainWorker.cpp
    src/Logger.h
    src/PluginManager.h
)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#target_link_libraries(Qt5::WinMain)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
)

qt5_use_modules(${PROJECT_NAME} Widgets)
