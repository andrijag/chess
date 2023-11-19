#include "Player.h"

namespace chess
{
    Player::Player(Color color) : color{color}
    {
    }

    Color Player::getColor() const
    {
        return color;
    }

    void Player::stopTime(ChessClock &chessClock) const
    {
        if (color == Color::white)
            chessClock.stopWhite();
        else
            chessClock.stopBlack();
    }
}