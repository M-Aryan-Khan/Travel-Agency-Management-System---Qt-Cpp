cmake_minimum_required(VERSION 3.5)

project(TravelAgencySystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.1/mingw_64" ${CMAKE_PREFIX_PATH})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        login.cpp login.h login.ui
        customers.h admin.h tripPackages.h
        addpackage.h addpackage.cpp addpackage.ui
        addusers.h addusers.cpp addusers.ui
        changepassword.h changepassword.cpp changepassword.ui
        deletepackage.h deletepackage.cpp deletepackage.ui
        deleteusers.h deleteusers.cpp deleteusers.ui
        editadmininfo.h editadmininfo.cpp editadmininfo.ui
        searchpackage.h searchpackage.cpp searchpackage.ui
        searchusers.h searchusers.cpp searchusers.ui
        system.h system.cpp system.ui
        updatepackage.h updatepackage.cpp updatepackage.ui
        updateusers.h updateusers.cpp updateusers.ui
        viewadmininfo.h viewadmininfo.cpp viewadmininfo.ui
)

qt6_add_resources(QT_RESOURCES pics.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TravelAgencySystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${QT_RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TravelAgencySystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TravelAgencySystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TravelAgencySystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TravelAgencySystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(TravelAgencySystem PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TravelAgencySystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TravelAgencySystem)
endif()
