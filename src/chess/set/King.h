#ifndef KING_H
#define KING_H

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
    class King : public ChessPiece
    {
    private:
        bool moved{false};

    public:
        explicit King(Color);

        std::unique_ptr<ChessPiece> clone() const override;
        void accept(Visitor &) const override;
        std::vector<Position> getMovePattern(const Chessboard &, Position) const override;
        bool isMoved() const;
        void setMoved(bool);

    private:
        std::vector<Direction> getMoveDirections() const;
    };
}

#endif