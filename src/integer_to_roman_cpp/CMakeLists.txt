list(APPEND SOURCE_FILES "src/Solution.cc")
add_library(integer_to_roman ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(integer_to_roman PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
  integer_to_roman_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
