cmake_minimum_required(VERSION 3.0)

# Basic information about project

project(vtmine VERSION 1.0)


set(SOURCE_FILES
    src/main.cpp
    src/i_framework.h
    src/framework_def_impl.h
    src/framework_def_impl.cpp
    src/logger.h
    src/plugin_manager.h
    src/app_starter.h
    src/app_starter.cpp
    src/cmd_line_params.h
    src/cmd_line_params.cpp
    src/framework_settings.h
    src/framework_settings.cpp
)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#target_link_libraries(Qt5::WinMain)

add_executable(${PROJECT_NAME}
    ${SOURCE_FILES}
)

qt5_use_modules(${PROJECT_NAME} Widgets)
