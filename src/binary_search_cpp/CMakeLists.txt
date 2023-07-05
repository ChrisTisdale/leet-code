file(GLOB SOURCE_FILES "src/*.h" "src/*.cc")
add_library(binary_search ${SOURCE_FILES})

target_compile_features(binary_search PUBLIC cxx_std_20)

file(GLOB TEST_FILES "tests/*.h" "tests/*.cc" "src/*.h" "src/*.cc")

package_add_test(
  binary_search_tests
  ${TEST_FILES}
)
