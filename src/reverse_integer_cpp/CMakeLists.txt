file(GLOB REVERSE_INTEGER_SOURCE "src/*.h" "src/*.cc")
add_library(reverse_integer ${REVERSE_INTEGER_SOURCE})

target_compile_features(reverse_integer PUBLIC cxx_std_20)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  reverse_integer_tests
  ${TEST_FILES}
)
