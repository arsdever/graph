add_library(stdafx STATIC stdafx.hpp stdafx.cpp)
target_include_directories(stdafx PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(stdafx PUBLIC stdafx.hpp)
