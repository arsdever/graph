cmake_minimum_required(VERSION 3.10)

project(graph)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_SAMPLES "Build Samples" OFF)
option(BUILD_TESTING "Build tests" OFF)

if(BUILD_SAMPLES)
  add_subdirectory(samples)
endif()

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
