set(LIST_NODE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE INTERNAL PARENT_SCOPE)
add_library(list_node INTERFACE)
target_sources(list_node INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src/ListNode.h")

target_include_directories(list_node INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")