#include "Move.h"

namespace chess
{
    Move::Move(Chessboard &board, Position source, Position destination)
        : board{board}, source{source}, destination{destination}
    {
    }

    void Move::execute() const
    {
        board.move(source, destination);
    }
}