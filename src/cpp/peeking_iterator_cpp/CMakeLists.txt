list(APPEND SOURCE_FILES "src/Iterator.cc")
list(APPEND SOURCE_FILES "src/Iterator.h")
list(APPEND SOURCE_FILES "src/PeekingIterator.cc")
list(APPEND SOURCE_FILES "src/PeekingIterator.h")

add_library(peeking_iterator ${SOURCE_FILES})
target_link_libraries(peeking_iterator)
target_compile_features(peeking_iterator PUBLIC cxx_std_23)

list(APPEND TEST_FILES "tests/lib_tests.cc")

package_add_test(
  peeking_iterator_tests
  ${TEST_FILES}
  ${SOURCE_FILES}
)
