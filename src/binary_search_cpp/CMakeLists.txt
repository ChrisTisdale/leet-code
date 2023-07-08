list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND ADD_TWO_NUMBERS_FILES "src/Solution.h")
add_library(binary_search ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(binary_search PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
  binary_search_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
