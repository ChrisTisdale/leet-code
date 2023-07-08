list(APPEND SOURCE_FILES "src/Solution.cc")
add_library(reverse_integer ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(reverse_integer PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  reverse_integer_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
