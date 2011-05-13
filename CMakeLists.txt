cmake_minimum_required (VERSION 2.6)
PROJECT(gmopen)

SET(BUILD_SHARED_LIBS true)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/find)

include_directories(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

##################################################
#                   gm open                      #
##################################################

FIND_PACKAGE(Qt4 REQUIRED)
SET(QT_USE_QTOPENGL TRUE)

FIND_PACKAGE(QGLViewer)
INCLUDE_DIRECTORIES(${QGLVIEWER_INCLUDE_DIR})

SET(gmopen_SOURCES      src/gui/glcolor.cpp
                        src/gui/triangle.cpp
                        src/gui/vertex.cpp
                        src/gui/mesh.cpp
                        src/gui/glviewer.cpp
                        src/gui/window.cpp
                        src/main.cpp)

SET(gmopen_HEADERS      src/gui/glcolor.h
                        src/gui/vec3D.h
                        src/gui/triangle.h
                        src/gui/vertex.h
                        src/gui/edge.h
                        src/gui/mesh.h
                        src/gui/glviewer.h
                        src/gui/window.h)

QT4_WRAP_CPP(gmopen_HEADERS_MOC ${gmopen_HEADERS})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_EXECUTABLE(gmopen 
                      ${gmopen_SOURCES}
                      ${gmopen_HEADERS_MOC})
INCLUDE_DIRECTORIES ( ${CMAKE_CURRENT_BINARY_DIR}
                      ${QT_INCLUDE_DIR}
                      ${QT_QTOPENGL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(gmopen
                      ${LIBS}
                      ${QT_LIBRARIES}
                      ${QT_QTOPENGL_LIBRARIES}
                      ${QGLVIEWER_LIBRARIES})


