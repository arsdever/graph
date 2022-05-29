cmake_minimum_required(VERSION 3.10)

project(graph)

# helps on github codespaces
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

option(BUILD_SAMPLES "Build Samples" OFF)
option(BUILD_TESTING "Build tests" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_SAMPLES)
  add_subdirectory(samples)
endif()

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()
