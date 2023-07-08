list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND ADD_TWO_NUMBERS_FILES "src/Solution.h")
add_library(longest_no_repeat ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(longest_no_repeat list_node)
target_compile_features(longest_no_repeat PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
  longest_no_repeat_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
