# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/externals/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif ()

project("leet-code")

set(CMAKE_CXX_STANDARD 23)
set(gtest_force_shared_crt on)
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "" FORCE)

option(PACKAGE_TESTS "Build the tests" ON)
if (PACKAGE_TESTS)
    include(GoogleTest)
    find_package(GTest CONFIG REQUIRED)
    mark_as_advanced(
            BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
            GTest::gmock_build_tests GTest::gtest_build_samples GTest::gtest_build_tests
            GTest::gtest_disable_pthreads GTest::gtest_force_shared_crt GTest::gtest_hide_internal_symbols
    )
endif ()

macro(package_add_test TESTNAME)
    if (PACKAGE_TESTS)
        enable_testing()
        # create an executable in which the tests will be stored
        add_executable(${TESTNAME} ${ARGN})
        # link the Google test infrastructure, mocking library, and a default main function to
        # the test executable.  Remove g_test_main if writing your own main function.
        target_link_libraries(${TESTNAME} PRIVATE GTest::gtest GTest::gmock GTest::gtest_main)
        # gtest_discover_tests replaces gtest_add_tests,
        # see https://cmake.org/cmake/help/v3.10/module/GoogleTest.html for more options to pass to it
        gtest_discover_tests(${TESTNAME}
                # set a working directory so your project root so that you can find test data via paths relative to the project root
                WORKING_DIRECTORY ${PROJECT_DIR}
                PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
        )
        set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
    endif ()
endmacro()

if (PACKAGE_TESTS)
    enable_testing()
endif ()

add_subdirectory("src/cpp/list_node_cpp")
add_subdirectory("src/cpp/add_two_numbers_cpp")
add_subdirectory("src/cpp/binary_search_cpp")
add_subdirectory("src/cpp/container_with_most_water")
add_subdirectory("src/cpp/evaluate_reverse_polish_notation")
add_subdirectory("src/cpp/find_the_duplicate_number")
add_subdirectory("src/cpp/generate_parentheses")
add_subdirectory("src/cpp/integer_to_roman_cpp")
add_subdirectory("src/cpp/letter_combinations_numbers_cpp")
add_subdirectory("src/cpp/longest_no_repeat_cpp")
add_subdirectory("src/cpp/merge_k_sorted_lists")
add_subdirectory("src/cpp/multiply_strings")
add_subdirectory("src/cpp/pairs_spells_potions_cpp")
add_subdirectory("src/cpp/peeking_iterator_cpp")
add_subdirectory("src/cpp/remove_nth_node_cpp")
add_subdirectory("src/cpp/reverse_integer_cpp")
add_subdirectory("src/cpp/reverse_linked_list_cpp")
add_subdirectory("src/cpp/reverse_linked_list_ii_cpp")
add_subdirectory("src/cpp/reverse_nodes_in_k_group")
add_subdirectory("src/cpp/roman_to_integer_cpp")
add_subdirectory("src/cpp/two_sum_cpp")
add_subdirectory("src/cpp/valid_parentheses_cpp")
add_subdirectory("src/cpp/valid_sudoku_cpp")
