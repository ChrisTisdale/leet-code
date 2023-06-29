file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(longest_no_repeat ${SOURCE_FILES})

target_compile_features(longest_no_repeat PUBLIC cxx_std_20)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

enable_testing()

package_add_test(
  longest_no_repeat_tests
  ${TEST_FILES}
)
