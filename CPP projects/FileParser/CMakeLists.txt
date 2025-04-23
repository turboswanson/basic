cmake_minimum_required(VERSION 3.16)

project(FileParser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml Gui)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_resources(APP_RESOURCES resources/resources.qrc)

qt_add_executable(appFileParser
    main.cpp
     ${APP_RESOURCES}

)

qt_add_qml_module(appFileParser
    URI FileParser
    VERSION 1.0
    QML_FILES
        resources/appView.qml
    SOURCES
        word_count_model/word_count_model.cpp
        word_count_model/word_count_model.h
        file_processor/file_processor.cpp
        file_processor/file_processor.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFileParser PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFileParser
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFileParser
    PRIVATE Qt6::Core Qt6::Quick Qt6::Qml Qt6::Gui
)

include(GNUInstallDirs)
install(TARGETS appFileParser
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
