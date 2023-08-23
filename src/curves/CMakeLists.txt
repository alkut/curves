project(curves-lib
        LANGUAGES CXX
        VERSION 0.0.0)

set(SOURCES
        Circle.cpp
        Ellipse.cpp)

if (BUILD_SHARED)
    message(STATUS "building shared lib")
    add_library(curves-lib SHARED ${SOURCES})
else ()
    message(STATUS "building static lib")
    add_library(curves-lib STATIC ${SOURCES})
endif ()