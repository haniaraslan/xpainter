cmake_minimum_required(VERSION 3.5)

project(xpainter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS PrintSupport)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  GUISupportQt
  RenderingQt
)


#find_package(Qt5PrintSupport REQUIRED)
#add_executable(test_prog WIN32 ${test_prog_SRCS})
#target_link_libraries(test_prog Qt5::PrintSupport)

set(PROJECT_SOURCES
        main.cpp
        paint3d.cpp
        paint3d.h
        paint3d.ui
        drawarea.h
        drawarea.cpp
        drawarea.ui
		Brushes.h
		Brushes.cpp
		shapes2D.h
		shapes2D.cpp
		Resources/resources.qrc

)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "xPainter: Unable to find the VTK build folder.")
endif()

set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(xpainter
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET xpainter APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(xpainter SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(xpainter
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(xpainter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
#target_link_libraries(xpainter PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(xpainter PRIVATE ${VTK_LIBRARIES})

set_target_properties(xpainter PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS xpainter
    BUNDLE DESTINATION .
	RUNTIME DESTINATION BIN ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION LIB ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(xpainter)
endif()

vtk_module_autoinit(
  TARGETS xpainter
  MODULES ${VTK_LIBRARIES}
)

