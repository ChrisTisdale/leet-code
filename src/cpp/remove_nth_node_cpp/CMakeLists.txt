list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(remove_nth_node ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(remove_nth_node list_node)
target_compile_features(remove_nth_node PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  remove_nth_node_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
