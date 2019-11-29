cmake_minimum_required(VERSION 3.15)
project(minimum_lib)


add_executable(test_either either/test-main.cc)
target_link_libraries(test_either gtest)

add_executable(test_string_algorithm string-algorithm/test-main.cc)
target_link_libraries(test_string_algorithm gtest)

add_executable(test_pool pool/test-main.cc)
target_link_libraries(test_pool gtest)

add_executable(test_container container/test-main.cc)
target_link_libraries(test_container gtest)



