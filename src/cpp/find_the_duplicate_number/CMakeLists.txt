list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(find_duplicate_numbers ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(find_duplicate_numbers PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
        find_duplicate_numbers_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
