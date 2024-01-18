#ifndef PAWN_MOVE_STRATEGY_H
#define PAWN_MOVE_STRATEGY_H

#include <memory>
#include <vector>

#include "Chessboard.h"
#include "Color.h"
#include "Direction.h"
#include "MoveCommand.h"
#include "MoveStrategy.h"
#include "Position.h"

namespace chess
{
    class PawnMoveStrategy : public MoveStrategy
    {
    public:
        virtual std::vector<std::unique_ptr<MoveCommand>>
        getMovePattern(Chessboard &, Position) const override;

    private:
        Direction getMoveDirection(Color) const;
        std::vector<Direction> getCaptureDirections(Direction) const;
    };
}

#endif