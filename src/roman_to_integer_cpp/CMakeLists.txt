file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(roman_to_integer ${SOURCE_FILES})

target_compile_features(roman_to_integer PUBLIC cxx_std_23)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  roman_to_integer_tests
  ${TEST_FILES}
)
