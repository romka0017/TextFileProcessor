cmake_minimum_required(VERSION 3.16)

project(TextFileProcessor)

include_directories(../include)
include_directories(../libs)

set(SOURCE_EXE TextFileProcessor.cpp)

add_executable(TextFileProcessor ${SOURCE_EXE})
add_subdirectory(../src pwd)

target_link_libraries(TextFileProcessor ProcessorLib)
