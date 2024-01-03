#ifndef CHESS_H
#define CHESS_H

#include <utility>

#include "Chessboard.h"
#include "ChessClock.h"
#include "Color.h"
#include "Observable.h"
#include "Player.h"
#include "Position.h"
#include "Rules.h"

namespace chess
{
    class Chess : public Observable
    {
    private:
        ChessClock clock;
        Chessboard board;
        std::pair<Player, Player> players{Player{Color::white}, Player{Color::black}};
        Player *currentPlayer{&players.first};
        Rules rules;

    public:
        Chess();

        void move(Position, Position);

    private:
        void nextPlayer();
    };
}

#endif