cmake_minimum_required (VERSION 2.6)
PROJECT(gmopen)

SET(BUILD_SHARED_LIBS true)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})

include_directories(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

##################################################
#                   gm open                      #
##################################################

FIND_PACKAGE(Qt4 REQUIRED)

SET(gmopen_SOURCES      src/gui/gmmodule.cpp
                        src/gui/gmdesktop_module.cpp
                        src/gui/gmmodulemanager_module.cpp
                        src/gui/gmtabmanager_module.cpp
                        src/gui/gmdevicemanager_module.cpp
                        src/gui/gmraw_module.cpp
                        src/gui/gmtd_module.cpp
                        src/gui/gmworkspace_module.cpp
                        src/gui/gmgroup.cpp
                        src/gui/gmhome_group.cpp
                        src/gui/gmdata_group.cpp
                        src/gui/gmgeneric_group.cpp
                        src/gui/mainwindow.cpp
                        src/Main.cpp)
SET(gmopen_HEADERS      src/gui/gmmodule.h
                        src/gui/gmdesktop_module.h
                        src/gui/gmmodulemanager_module.h
                        src/gui/gmtabmanager_module.h
                        src/gui/gmdevicemanager_module.h
                        src/gui/gmraw_module.h
                        src/gui/gmtd_module.h
                        src/gui/gmworkspace_module.h
                        src/gui/gmgroup.h
                        src/gui/gmhome_group.h
                        src/gui/gmdata_group.h
                        src/gui/gmgeneric_group.h
                        src/gui/mainwindow.h)

QT4_WRAP_CPP(gmopen_HEADERS_MOC ${gmopen_HEADERS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_EXECUTABLE(gmopen ${gmopen_SOURCES} ${gmopen_HEADERS_MOC})
TARGET_LINK_LIBRARIES(gmopen epoc ${LIBS} ${QT_LIBRARIES})



