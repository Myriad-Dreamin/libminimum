cmake_minimum_required(VERSION 3.15)
project(minimum_lib)

message(${CMAKE_SYSTEM_NAME})

set(CMAKE_CXX_STANDARD 17)

set(LIBRARIES
        pthread)
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

link_directories(./googletest)

include_directories(include)

add_subdirectory(example)
add_subdirectory(test)


