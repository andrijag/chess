#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

#include "ChessPiece.h"
#include "Color.h"
#include "Visitable.h"
#include "Visitor.h"

namespace chess
{
    class Chessboard;

    class Square : public Visitable
    {
    private:
        Color color;
        std::unique_ptr<ChessPiece> chessPiece{nullptr};

    public:
        explicit Square(Color);
        ~Square() = default;
        Square(const Square &);
        Square &operator=(const Square &);
        Square(Square &&) = default;
        Square &operator=(Square &&) = default;

        Color getColor() const;
        ChessPiece *getChessPiece() const;
        bool isEmpty() const;
        void accept(Visitor &) const override;

    private:
        friend Chessboard;
        std::unique_ptr<ChessPiece> getChessPieceOwnership();
        void setChessPiece(std::unique_ptr<ChessPiece>);
    };
}

#endif