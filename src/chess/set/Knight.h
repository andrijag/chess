#ifndef KNIGHT_H
#define KNIGHT_H

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
    class Knight : public ChessPiece
    {
    public:
        explicit Knight(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        std::vector<Position> getMovePattern(const Chessboard &, Position) const override;

    private:
        std::vector<Direction> getMoveDirections() const;
    };
}

#endif