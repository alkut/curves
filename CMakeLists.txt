cmake_minimum_required(VERSION 3.27)
project(curves)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)
add_subdirectory(src/curves)

include(cmake/Env.cmake)
include(cmake/Options.cmake)
