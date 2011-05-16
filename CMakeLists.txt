cmake_minimum_required (VERSION 2.6)
PROJECT(gmopen)

SET(BUILD_SHARED_LIBS true)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/find)

include_directories(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

##################################################
#                   emokit                       #
##################################################

FIND_PACKAGE(Mcrypt REQUIRED)

IF(WIN32)
  SET(WDK_PATH CACHE PATH "Path to WDK Installation")
  INCLUDE_DIRECTORIES(${WDK_PATH}/inc/api ${WDK_PATH}/inc/crt ${WDK_PATH}/inc)
  LINK_DIRECTORIES(${WDK_PATH}/lib/wxp/i386)
  LIST(APPEND LIBEPOC_REQUIRED_LIBS hid setupapi)
ELSEIF(UNIX)
  FIND_PACKAGE(libusb-1.0 REQUIRED)
  IF(LIBUSB_1_FOUND)
    INCLUDE_DIRECTORIES(${LIBUSB_1_INCLUDE_DIRS})
    LIST(APPEND LIBEPOC_REQUIRED_LIBS ${LIBUSB_1_LIBRARIES})
  ENDIF(LIBUSB_1_FOUND)
ENDIF(WIN32)

SET(LIBS ${Mcrypt_LIBS} ${LIBUSB_1_LIBRARIES})
INCLUDE_DIRECTORIES(${libepoc_SOURCE_DIR}/driver)
SET(LIBEPOC_HEADERS driver/libepoc.h)

ADD_SUBDIRECTORY(driver)

#################################################
#                   PKGCONFIG file              #
#################################################

IF   (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libepoc.pc.in")
    MESSAGE(STATUS "configured ${CMAKE_CURRENT_SOURCE_DIR}/libepoc.pc.in --> ${CMAKE_CURRENT_BINARY_DIR}/libepoc.pc")
    CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/libepoc.pc.in 
      ${CMAKE_CURRENT_BINARY_DIR}/libepoc.pc
      @ONLY )

	INSTALL(FILES
		${CMAKE_CURRENT_BINARY_DIR}/libepoc.pc
		DESTINATION lib/pkgconfig
	)
ENDIF(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libepoc.pc.in")


##################################################
#                   gm open                      #
##################################################

FIND_PACKAGE(Qt4 REQUIRED)
SET(QT_USE_QTOPENGL TRUE)

FIND_PACKAGE(QGLViewer)
INCLUDE_DIRECTORIES(${QGLVIEWER_INCLUDE_DIR})

SET(gmopen_SOURCES      driver/epoc.c
                        driver/epoc_libusb.c
                        src/gui/glcolor.cpp
                        src/gui/triangle.cpp
                        src/gui/vertex.cpp
                        src/gui/mesh.cpp
                        src/gui/epoc.cpp
                        src/gui/glviewer.cpp
                        src/gui/window.cpp
                        src/main.cpp)

SET(gmopen_HEADERS      src/gui/glcolor.h
                        src/gui/vec3D.h
                        src/gui/triangle.h
                        src/gui/vertex.h
                        src/gui/edge.h
                        src/gui/mesh.h
                        src/gui/epoc.h
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
