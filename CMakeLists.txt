cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(simpleNN)

find_package(Torch REQUIRED)

set( SOURCES dataset.cpp dataset.h)

add_executable(simpleNN ${SOURCES} simpleNN.cpp)
target_link_libraries(simpleNN "${TORCH_LIBRARIES}")
set_property(TARGET simpleNN PROPERTY CXX_STANDARD 11)
