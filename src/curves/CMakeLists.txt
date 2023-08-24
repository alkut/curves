project(curves-lib)

set(SOURCES
        Circle.cpp
        Ellipse.cpp
        Helix.cpp)

if (BUILD_SHARED)
    message(STATUS "building shared lib")
    add_library(curves-lib SHARED ${SOURCES})
else ()
    message(STATUS "building static lib")
    add_library(curves-lib STATIC ${SOURCES})
endif ()