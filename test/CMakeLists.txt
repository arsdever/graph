include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG e2239ee # v1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(test_unit_graph graph_test.cpp)
add_executable(test::unit::graph ALIAS test_unit_graph)

target_link_libraries(test_unit_graph gtest_main stdafx)

target_precompile_headers(test_unit_graph REUSE_FROM stdafx)

include(GoogleTest)
gtest_discover_tests(test_unit_graph)
