cmake_minimum_required(VERSION 3.16)
project(projet_cpp)
set(CMAKE_CXX_STANDARD 14)

add_executable(projet_cpp src/main.cpp src/SequenceD.cpp include/SequenceD.h src/Sequence.cpp include/Sequence.h)

add_subdirectory(google_tests)