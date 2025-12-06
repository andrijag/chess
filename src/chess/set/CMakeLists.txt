add_library(ChessSet)

target_sources(ChessSet
    PRIVATE
        Chessboard.cpp
        Square.cpp
        ChessPiece.cpp
        King.cpp
        Queen.cpp
        Rook.cpp
        Bishop.cpp
        Knight.cpp
        Pawn.cpp
    PUBLIC
        FILE_SET HEADERS
)