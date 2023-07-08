list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND ADD_TWO_NUMBERS_FILES "src/Solution.h")
add_library(letter_combinations_numbers ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_compile_features(letter_combinations_numbers PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  letter_combinations_numbers_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
