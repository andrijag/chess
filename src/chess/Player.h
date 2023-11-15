#ifndef PLAYER_H
#define PLAYER_H

#include "ChessClock.h"
#include "Color.h"

namespace chess
{
    class Player
    {
    private:
        Color color;

    public:
        explicit Player(Color);

        void stopTime(ChessClock &) const;
    };
}

#endif