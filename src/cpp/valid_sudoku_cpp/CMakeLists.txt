list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(valid_sudoku ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(valid_sudoku PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  valid_sudoku_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
