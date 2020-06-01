include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${projet_SOURCE_DIR}/include ${projet_SOURCE_DIR}/src/DES)

add_executable(runtest basicTest.cpp SequenceTest.cpp SequenceDTest.cpp PermutationTest.cpp)

target_link_libraries(runtest gtest gtest_main)
target_link_libraries(runtest DES)
