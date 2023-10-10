cmake_minimum_required(VERSION 3.0.0)
project(Chess VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

add_subdirectory(src/chessclock)

add_executable(Chess main.cpp)

target_link_libraries(Chess PUBLIC ChessClock)

target_include_directories(Chess PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src/chessclock")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
