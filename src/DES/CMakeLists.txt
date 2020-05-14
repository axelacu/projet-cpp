cmake_minimum_required(VERSION 3.16)
include_directories(${projet_SOURCE_DIR}/include)

add_library(DES
        SequenceD.cpp
        ${projet_SOURCE_DIR}/include/SequenceD.h
        Sequence.cpp
        ${projet_SOURCE_DIR}/include/Sequence.h
        test.cpp
        ${projet_SOURCE_DIR}/include/test.h
        )