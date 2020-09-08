cmake_minimum_required(VERSION 3.16)

project(ProcessorLib)

include_directories(../include)

set(SOURCE_LIB dataprocessor.cpp fileprocessor.cpp inputparameters.cpp)

add_library(ProcessorLib SHARED ${SOURCE_LIB})