add_library(Chess)

target_sources(Chess
    PRIVATE
        Chess.cpp
        Observable.cpp
        Player.cpp
    PUBLIC
        FILE_SET HEADERS
)

target_link_libraries(Chess
    PRIVATE
        ChessClock
        ChessSet
)

add_subdirectory(clock)
add_subdirectory(set)

target_include_directories(Chess PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/clock"
    "${CMAKE_CURRENT_SOURCE_DIR}/set"
)