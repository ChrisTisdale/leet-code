file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(integer_to_roman ${SOURCE_FILES})

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

enable_testing()

add_executable(
  integer_to_roman_tests
  ${TEST_FILES}
)
target_link_libraries(
  integer_to_roman_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(integer_to_roman_tests)
