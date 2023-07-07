file(GLOB LETTER_COMBINATIONS_NUMBERS_FILES "src/*.h" "src/*.cc")
add_library(letter_combinations_numbers ${LETTER_COMBINATIONS_NUMBERS_FILES})

target_compile_features(letter_combinations_numbers PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  letter_combinations_numbers_tests
  ${TEST_FILES}
)
