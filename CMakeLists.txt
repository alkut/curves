cmake_minimum_required(VERSION 3.22)
project(curves)

set(CMAKE_CXX_STANDARD 23)

if (NOT BINARY_IN_BUILD)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif ()

include_directories(include)

include(cmake/Env.cmake)
include(cmake/Options.cmake)

add_subdirectory(src/curves)
add_subdirectory(examples)
