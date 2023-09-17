list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(two_sum ${SOURCE_FILES})
target_compile_features(two_sum PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  two_sum_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
