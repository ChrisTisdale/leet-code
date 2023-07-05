file(GLOB LETTER_COMBINATIONS_NUMBERS_FILES "src/*.h" "src/*.cc")
add_library(LETTER_COMBINATIONS_NUMBERS ${LETTER_COMBINATIONS_NUMBERS_FILES})

target_compile_features(LETTER_COMBINATIONS_NUMBERS PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  letter_combinations_numbers_tests
  ${TEST_FILES}
)
