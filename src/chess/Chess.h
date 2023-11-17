#ifndef CHESS_H
#define CHESS_H

#include <utility>

#include "Chessboard.h"
#include "ChessClock.h"
#include "King.h"
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
        void nextPlayer();
    };
}

#endif