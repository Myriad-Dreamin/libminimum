cmake_minimum_required(VERSION 3.15)
project(minimum_lib)

set(CMAKE_CXX_STANDARD 17)

# example print

add_executable(example_hello_world print.cc)
target_compile_definitions(example_hello_world PRIVATE HelloWorld)

add_executable(example_boolean print.cc)
target_compile_definitions(example_boolean PRIVATE Boolean)

add_executable(example_pair print.cc)
target_compile_definitions(example_pair PRIVATE Pair)

add_executable(example_serial_container print.cc)
target_compile_definitions(example_serial_container PRIVATE SerialContainer)

add_executable(example_query_like_container print.cc)
target_compile_definitions(example_query_like_container PRIVATE QueueLikeContainer)

add_executable(example_combining_container print.cc)
target_compile_definitions(example_combining_container PRIVATE CombiningContainer)

# example graph
add_executable(example_fixed_graph graph.cc)
target_compile_definitions(example_fixed_graph PRIVATE Fix)

add_executable(example_not_fixed_graph graph.cc)
target_compile_definitions(example_not_fixed_graph PRIVATE NFix)

