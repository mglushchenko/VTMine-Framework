add_executable(vtmine_core
    i_framework.h
    framework_def_impl.h
    framework_def_impl.cpp
    logger.h
    plugin_manager.h
    app_starter.h
    app_starter.cpp
    cmd_line_params.h
    cmd_line_params.cpp
    framework_settings.h
    framework_settings.cpp
)

target_link_libraries(vtmine_core Qt5::Widgets)