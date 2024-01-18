#ifndef BISHOP_MOVE_STRATEGY_H
#define BISHOP_MOVE_STRATEGY_H

#include <memory>
#include <vector>

#include "Chessboard.h"
#include "Direction.h"
#include "MoveCommand.h"
#include "MoveStrategy.h"
#include "Position.h"

namespace chess
{
    class BishopMoveStrategy : public MoveStrategy
    {
    public:
        virtual std::vector<std::unique_ptr<MoveCommand>>
        getMovePattern(Chessboard &, Position) const override;

    private:
        std::vector<Direction> getMoveDirections() const;
    };
}

#endif