cmake_minimum_required(VERSION 3.5)

project(informatica_avanzada VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(includes)

set(PROJECT_SOURCES
        src/main.cpp

        includes/database/database.hpp

        includes/windows/mainwindow.h
        src/windows/mainwindow.cpp
        src/windows/mainwindow.ui

        includes/windows/equipotecnicowindow.h
        src/windows/equipotecnicowindow.cpp
        src/windows/equipotecnicowindow.ui
        
        includes/usuarios/usuarios.h
        src/usuarios/usuarios.cpp

        includes/usuarios/ventanadatosusuario.h
        src/usuarios/ventanadatosusuario.cpp
        src/usuarios/ventanadatosusuario.ui

        includes/usuarios/buscarcrearusuario.h
        src/usuarios/buscarcrearusuario.cpp
        src/usuarios/buscarcrearusuario.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(informatica_avanzada
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET informatica_avanzada APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(informatica_avanzada SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(informatica_avanzada
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(informatica_avanzada PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(informatica_avanzada PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_add_resources(informatica_avanzada "app_images"
    PREFIX "/"
    FILES images/uclm-logo.png
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(informatica_avanzada)
endif()
