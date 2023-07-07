file(GLOB VALID_SUDOKU_FILES "src/*.h" "src/*.cc")
add_library(valid_sudoku ${VALID_SUDOKU_FILES})

target_compile_features(valid_sudoku PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  valid_sudoku_tests
  ${TEST_FILES}
)
