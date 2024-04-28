list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(merge_k_sorted_lists ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(merge_k_sorted_lists list_node)
target_compile_features(merge_k_sorted_lists PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
        merge_k_sorted_lists_tests
        ${TEST_FILES}
        ${SOURCE_FILES}
)
