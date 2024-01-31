list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(evaluate_reverse_polish_notation ${SOURCE_FILES})
target_link_libraries(evaluate_reverse_polish_notation list_node)
target_compile_features(evaluate_reverse_polish_notation PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  evaluate_reverse_polish_notation_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
