add_subdirectory(clock)
add_subdirectory(set)

add_library(Chess Chess.cpp Observable.cpp Player.cpp Rules.cpp
KingMoveStrategy.cpp QueenMoveStrategy.cpp RookMoveStrategy.cpp BishopMoveStrategy.cpp KnightMoveStrategy.cpp PawnMoveStrategy.cpp
Move.cpp)

target_link_libraries(Chess PUBLIC ChessClock ChessSet)

target_include_directories(Chess PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/clock"
    "${CMAKE_CURRENT_SOURCE_DIR}/set"
)