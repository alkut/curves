project(generator-lib)

add_library(generator-lib STATIC generator.cpp)

target_link_libraries(generator-lib PRIVATE curves-lib)