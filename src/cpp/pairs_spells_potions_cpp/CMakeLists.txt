list(APPEND SOURCE_FILES "src/Solution.cc")
list(APPEND SOURCE_FILES "src/Solution.h")
add_library(pairs_spells_potions ${SOURCE_FILES})
include_directories(${LIST_NODE_INCLUDE})
target_link_libraries(pairs_spells_potions list_node)
target_compile_features(pairs_spells_potions PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/solution_tests.cc")

package_add_test(
  pairs_spells_potions_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
