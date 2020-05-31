cmake_minimum_required(VERSION 3.16)
include_directories(${projet_SOURCE_DIR}/include ${projet_SOURCE_DIR}/src/DES)

add_executable(MAIN_RUN_2 main_olivier.cpp)

target_link_libraries(MAIN_RUN_2 DES)