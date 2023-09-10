cmake_minimum_required(VERSION 3.5)

project(gpt_help VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)


set(PROJECT_SOURCES
        main.cc
        model/parser.h
        model/parser.cc
        model/Affines/TransformationStrategy.h
        model/Affines/GPUTransformation.h
        model/Affines/GPUTransformation.cc
        model/Affines/CPUTransformation.h
        model/Affines/CPUTransformation.cc
        controller/controller.h
        controller/controller.cc
        view/mainwindow.h
        view/mainwindow.cc
        view/mainwindow.ui
        view/widget.h
        view/widget.cc
        view/settings.h
        view/settings.cc
        view/ShaderFactory.h
        view/ShaderStates/ShaderState.h
        view/ShaderStates/ShaderNoGeometry.h
        view/ShaderStates/ShaderPointsOnly.h
        view/ShaderStates/ShaderCustomizableLines.h
        view/ShaderStates/ShaderEverythingButSlow.h
        view/style.qrc
        shaders.qrc
        view/3rdParty/gifmaker/dgif_lib.c
        view/3rdParty/gifmaker/egif_lib.c
        view/3rdParty/gifmaker/gif_err.c
        view/3rdParty/gifmaker/gif_font.c
        view/3rdParty/gifmaker/gif_hash.c
        view/3rdParty/gifmaker/gif_hash.h
        view/3rdParty/gifmaker/gif_lib_private.h
        view/3rdParty/gifmaker/gif_lib.h
        view/3rdParty/gifmaker/gifalloc.c
        view/3rdParty/gifmaker/qgifglobal.h
        view/3rdParty/gifmaker/qgifimage_p.h
        view/3rdParty/gifmaker/qgifimage.h
        view/3rdParty/gifmaker/quantize.c
        view/3rdParty/gifmaker/qgifimage.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(gpt_help
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET gpt_help APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(gpt_help SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(gpt_help
            ${PROJECT_SOURCES} ${QRC_SOURCES}
        )
    endif()
endif()

add_compile_options(-fsanitize=address -Wall -Werror -Wextra -std=c++17)
target_include_directories(gpt_help PRIVATE view/QGifImage)
target_link_libraries(gpt_help PRIVATE Qt${QT_VERSION_MAJOR}::Widgets -fsanitize=address)
target_link_libraries(gpt_help PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(gpt_help PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(gpt_help PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gpt_help)
endif()
