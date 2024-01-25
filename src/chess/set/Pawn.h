#ifndef PAWN_H
#define PAWN_H

#include <memory>
#include <vector>

#include "Chessboard.h"
#include "ChessPiece.h"
#include "Color.h"
#include "Direction.h"
#include "Position.h"
#include "Visitor.h"

namespace chess
{
    class Pawn : public ChessPiece
    {
    private:
        bool firstMove{true};

    public:
        explicit Pawn(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        std::vector<Position> getMovePattern(const Chessboard &, Position) const override;
        bool isFirstMove() const;
        void setFirstMove(bool);

    private:
        Direction getMoveDirection(Color) const;
        std::vector<Direction> getCaptureDirections(Color) const;
    };
}

#endif