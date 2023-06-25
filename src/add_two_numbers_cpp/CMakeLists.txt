file(GLOB ADD_TWO_NUMBERS_FILES "src/*.h" "src/*.cc")
add_library(add_two_numbers ${ADD_TWO_NUMBERS_FILES})

target_compile_features(add_two_numbers PUBLIC cxx_std_20)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

enable_testing()

add_executable(
  add_two_numbers_tests
  ${TEST_FILES}
)
target_link_libraries(
  add_two_numbers_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(add_two_numbers_tests)
