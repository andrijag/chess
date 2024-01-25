#ifndef MOVE_STRATEGY_H
#define MOVE_STRATEGY_H

#include <memory>
#include <vector>

#include "MoveCommand.h"
#include "Position.h"

namespace chess
{
    class Chessboard;

    class MoveStrategy
    {
    public:
        virtual ~MoveStrategy() = default;

        virtual std::vector<std::unique_ptr<MoveCommand>>
        getMovePattern(Chessboard &, Position) const = 0;
    };
}

#endif