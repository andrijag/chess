cmake_minimum_required(VERSION 3.23)

project(App VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(App)

target_sources(App
    PRIVATE
        main.cpp
)

target_link_libraries(App
    PRIVATE
        Chess
)

add_subdirectory(src/chess)