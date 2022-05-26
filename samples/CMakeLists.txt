include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(stdafx)

add_executable(dot_converter dot_converter.cpp)
target_link_libraries(dot_converter stdafx)
target_precompile_headers(dot_converter REUSE_FROM stdafx)
