cmake_minimum_required(VERSION 3.0)

# Basic information about project

project(VTMine VERSION 1.0)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(nlohmann_json 3.2.0 REQUIRED)


add_executable(VTMine 
    main.cpp
    core/framework.h
    core/framework_def_impl.h
    core/framework_def_impl.cpp
    core/logger.h
    core/plugin_manager.h
    core/app_starter.h
    core/app_starter.cpp
    core/cmd_line_params.h
    core/cmd_line_params.cpp
    core/framework_settings.h
    core/framework_settings.cpp
    core/vtmexception.h
    core/vtmexception.cpp
)
target_link_libraries(VTMine Qt5::Widgets)
#target_link_libraries(VTMine PRIVATE nlohmann_json::nlohmann_json)

#add_subdirectory(core)



#qt5_use_modules(vtmine Widgets)  # уточнить, должен ли быть здесь первым параметров target, а не имя проекта!
