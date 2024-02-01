list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(multiply_strings ${SOURCE_FILES})
target_compile_features(multiply_strings PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
  multiply_strings_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
