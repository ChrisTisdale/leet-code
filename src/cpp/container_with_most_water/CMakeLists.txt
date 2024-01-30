list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(container_with_most_water ${SOURCE_FILES})
target_link_libraries(container_with_most_water list_node)
target_compile_features(container_with_most_water PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  container_with_most_water_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
