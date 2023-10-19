cmake_minimum_required(VERSION 3.0.0)

project(Chess VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/chess/clock)

add_executable(Chess main.cpp)

target_link_libraries(Chess PUBLIC ChessClock)

target_include_directories(Chess PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src/chess/clock"
)