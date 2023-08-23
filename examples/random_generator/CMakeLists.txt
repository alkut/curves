project(generator)

add_library(generator STATIC generator.cpp)

target_link_libraries(generator PRIVATE curves-lib)