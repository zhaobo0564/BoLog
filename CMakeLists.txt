cmake_minimum_required(VERSION 3.23)
project(BoLog)
set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(src)
include_directories(src/include)


add_library(BOLOG src/sources/bo_log.cpp)

add_executable(BoLog src/main.cpp)

target_link_libraries(BoLog BOLOG)