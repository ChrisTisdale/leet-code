list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(reverse_linked_list ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(reverse_linked_list list_node)
target_compile_features(reverse_linked_list PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  reverse_linked_list_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
