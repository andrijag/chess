#ifndef CHESS_H
#define CHESS_H

#include <utility>
#include <unordered_set>

#include "Chessboard.h"
#include "ChessClock.h"
#include "Color.h"
#include "Observable.h"
#include "Player.h"
#include "Position.h"

namespace chess
{
    class Chess : public Observable
    {
    private:
        ChessClock clock;
        Chessboard board;
        std::pair<Player, Player> players{Player{Color::white}, Player{Color::black}};
        Player *currentPlayer{&players.first};

    public:
        Chess();

        void move(Position, Position);

    private:
        bool hasPossibleMoves(Color) const;
        std::unordered_set<Position> getPossibleMoves(Position) const;
        void nextPlayer();
    };

    void moveChessPiece(Chessboard &, Position, Position);
    bool isInCheck(const Chessboard &, Color);
    std::unordered_set<Position> getSquaresUnderAttack(const Chessboard &, Color);
}

#endif