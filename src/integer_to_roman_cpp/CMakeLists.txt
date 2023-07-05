file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(integer_to_roman ${SOURCE_FILES})

target_compile_features(integer_to_roman PUBLIC cxx_std_20)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  integer_to_roman_tests
  ${TEST_FILES}
)
