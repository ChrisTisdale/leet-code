list(APPEND ADD_TWO_NUMBERS_FILES "src/Solution.cc")
list(APPEND ADD_TWO_NUMBERS_FILES "src/Solution.h")
add_library(add_two_numbers ${ADD_TWO_NUMBERS_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(add_two_numbers list_node)
target_compile_features(add_two_numbers PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  add_two_numbers_tests
  ${TEST_FILES}
  ${ADD_TWO_NUMBERS_FILES}
)
