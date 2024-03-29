include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(../src)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(reductions_test
    sat_test.cpp
    hc_tsp_test.cpp
)

target_link_libraries(
  reductions_test
  reductions_lib
  GTest::gtest_main
  ${Boost_LIBRARIES}
)

include(GoogleTest)
gtest_discover_tests(reductions_test)