file(GLOB REMOVE_NTH_NODE_FILES "src/*.h" "src/*.cc")
add_library(remove_nth_node ${REMOVE_NTH_NODE_FILES})

target_compile_features(remove_nth_node PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  remove_nth_node_tests
  ${TEST_FILES}
)
