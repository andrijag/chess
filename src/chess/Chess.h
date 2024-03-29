#ifndef CHESS_H
#define CHESS_H

#include <utility>
#include <unordered_set>

#include "Chessboard.h"
#include "ChessClock.h"
#include "Color.h"
#include "GameState.h"
#include "Observable.h"
#include "Player.h"
#include "Position.h"

namespace chess
{
    // TODO: special moves (en passant, castling, pawn promotion)
    class Chess : public Observable
    {
    public:
        Chess();

        void move(Position, Position);
        void restart();

    private:
        void boardSetup();
        bool isLegalMove(Position, Position) const;
        void nextPlayer();
        bool isStalemate(Color) const;
        bool isCheckmated(Color) const;
        bool hasPossibleMoves(Color) const;
        std::unordered_set<Position> getPossibleMoves(Position) const;

    private:
        ChessClock clock;
        Chessboard board;
        std::pair<Player, Player> players{Player{Color::white}, Player{Color::black}};
        Player *currentPlayer{&players.first};
        GameState state{GameState::playing};
    };

    void moveChessPiece(Chessboard &, Position, Position);
    bool isInCheck(const Chessboard &, Color);
    std::unordered_set<Position> getSquaresUnderAttack(const Chessboard &, Color);
}

#endif