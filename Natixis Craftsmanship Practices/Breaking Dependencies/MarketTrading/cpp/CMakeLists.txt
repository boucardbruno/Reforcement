cmake_minimum_required(VERSION 4.0)
project(MarketData)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)