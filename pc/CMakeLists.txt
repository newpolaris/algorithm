cmake_minimum_required(VERSION 3.0.0)
project(pc VERSION 0.1.0)

include(CTest)
enable_testing()

# set(FILE "subset_sum.cpp")
set(FILE "permutation.cpp")

add_executable(pc ${FILE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
