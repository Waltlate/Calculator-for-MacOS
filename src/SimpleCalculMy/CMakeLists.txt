cmake_minimum_required(VERSION 3.5)

project(SimpleCalculMy VERSION 0.1 LANGUAGES CXX)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)


include_directories(    
    ${CMAKE_SOURCE_DIR}/Controller
    ${CMAKE_SOURCE_DIR}/View
    ${CMAKE_SOURCE_DIR}/Model
    ${CMAKE_SOURCE_DIR}
)

set(PROJECT_SOURCES
        main.cc
        View/mainwindow.cc
        View/mainwindow.h
        View/mainwindow.ui
        View/qcustomplot.cc
        View/qcustomplot.h
        Model/model.cc
        Model/model.h
        Controller/controller.cc
        Controller/controller.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SimpleCalculMy
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SimpleCalculMy APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SimpleCalculMy SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SimpleCalculMy
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SimpleCalculMy PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

set_target_properties(SimpleCalculMy PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SimpleCalculMy)
endif()
