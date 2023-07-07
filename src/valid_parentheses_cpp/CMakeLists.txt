file(GLOB VALID_PARENTHESES_FILES "src/*.h" "src/*.cc")
add_library(valid_parentheses ${VALID_PARENTHESES_FILES})

target_compile_features(valid_parentheses PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  valid_parentheses_tests
  ${TEST_FILES}
)
