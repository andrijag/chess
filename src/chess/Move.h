#ifndef MOVE_H
#define MOVE_H

#include "Chessboard.h"
#include "MoveCommand.h"
#include "Position.h"

namespace chess
{
    class Move : public MoveCommand
    {
    private:
        Chessboard &board;
        Position source;
        Position destination;

    public:
        Move(Chessboard &, Position, Position);
        void execute() const override;
    };
}

#endif