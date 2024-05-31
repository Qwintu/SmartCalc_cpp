cmake_minimum_required(VERSION 3.5)

project(SmartCalc VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# исправляет ошибку после щбновления
set(ENV{QT_PLUGIN_PATH} "/usr/local/Qt-6.6.2/plugins/")
set(ENV{CMAKE_PREFIX_PATH} "/usr/local/Qt-6.6.2/")
# end

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        plotwindow.h
        plotwindow.cpp
        plotwindow.ui

        ../Models/calc_model.cc
        ../Models/calc_model.h
        ../Controllers/calc_controller.cc
        ../Controllers/calc_controller.h

        ../Models/deposit_model.cc
        ../Models/deposit_model.h
        ../Controllers/deposit_controller.cc
        ../Controllers/deposit_controller.h

        ../Models/credit_model.cc
        ../Models/credit_model.h
        ../Controllers/credit_controller.cc
        ../Controllers/credit_controller.h

        ../Controllers/cred_output_data.h
        ../Controllers/cred_input_data.h
        qcustomplot.cpp
        qcustomplot.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SmartCalc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartCalc SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartCalc
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

find_package(Qt6 REQUIRED COMPONENTS PrintSupport)
target_link_libraries(SmartCalc PRIVATE Qt6::PrintSupport)

set_target_properties(SmartCalc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc)
endif()
