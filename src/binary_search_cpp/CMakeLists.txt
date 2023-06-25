file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(binary_search ${SOURCE_FILES})

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

enable_testing()

add_executable(
  binary_search_tests
  ${TEST_FILES}
)
target_link_libraries(
  binary_search_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(binary_search_tests)
