list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(generate_parentheses ${SOURCE_FILES})
target_compile_features(generate_parentheses PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  generate_parentheses_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
