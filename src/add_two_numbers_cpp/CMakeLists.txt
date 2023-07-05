file(GLOB ADD_TWO_NUMBERS_FILES "src/*.h" "src/*.cc")
add_library(add_two_numbers ${ADD_TWO_NUMBERS_FILES})

target_compile_features(add_two_numbers PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  add_two_numbers_tests
  ${TEST_FILES}
)
