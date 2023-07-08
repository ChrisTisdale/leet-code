list(APPEND SOURCE_FILES "src/Solution.cc")
add_library(remove_nth_node ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(remove_nth_node PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  remove_nth_node_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
