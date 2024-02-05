cmake_minimum_required(VERSION 3.0.0)

project(App VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/chess)

add_executable(App main.cpp)

target_link_libraries(App PUBLIC Chess)

target_include_directories(App PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src/chess"
)