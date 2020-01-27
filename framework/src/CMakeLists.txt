cmake_minimum_required(VERSION 3.0)

# Basic information about project

project(VTMine VERSION 1.0)


# set(SOURCE_FILES
    # src/main.cpp
    # src/i_framework.h
    # src/framework_def_impl.h
    # src/framework_def_impl.cpp
    # src/logger.h
    # src/plugin_manager.h
    # src/app_starter.h
    # src/app_starter.cpp
    # src/cmd_line_params.h
    # src/cmd_line_params.cpp
    # src/framework_settings.h
    # src/framework_settings.cpp
# )

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

#target_link_libraries(Qt5::WinMain)

# add_executable(${PROJECT_NAME}
    # ${SOURCE_FILES}
# )

add_executable(vtmine
    main.cpp
    core/i_framework.h
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
)


#qt5_use_modules(${PROJECT_NAME} Widgets)
qt5_use_modules(vtmine Widgets)  # уточнить, должен ли быть здесь первым параметров target, а не имя проекта!
