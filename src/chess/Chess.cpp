#include "Chess.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"

namespace chess
{
    Chess::Chess()
    {
        board.place({0, 0}, createChessPiece<Rook>(Color::black));
        board.place({0, 1}, createChessPiece<Bishop>(Color::black));
        board.place({0, 2}, createChessPiece<Knight>(Color::black));
        board.place({0, 3}, createChessPiece<Queen>(Color::black));
        board.place({0, 4}, createChessPiece<King>(Color::black));
        board.place({0, 5}, createChessPiece<Knight>(Color::black));
        board.place({0, 6}, createChessPiece<Bishop>(Color::black));
        board.place({0, 7}, createChessPiece<Rook>(Color::black));

        for (auto column = 0; column < 8; column++)
            board.place({1, column}, createChessPiece<Pawn>(Color::black));

        for (auto column = 0; column < 8; column++)
            board.place({6, column}, createChessPiece<Pawn>(Color::white));

        board.place({7, 0}, createChessPiece<Rook>(Color::white));
        board.place({7, 1}, createChessPiece<Bishop>(Color::white));
        board.place({7, 2}, createChessPiece<Knight>(Color::white));
        board.place({7, 3}, createChessPiece<Queen>(Color::white));
        board.place({7, 4}, createChessPiece<King>(Color::white));
        board.place({7, 5}, createChessPiece<Knight>(Color::white));
        board.place({7, 6}, createChessPiece<Bishop>(Color::white));
        board.place({7, 7}, createChessPiece<Rook>(Color::white));
    }

    void Chess::move(Position from, Position to)
    {
        if (!currentPlayer->isOwnPiece(board, from))
            return;
        // TODO
        board.getSquareView(from).accept(rules);
        currentPlayer->stopTime(clock);
        nextPlayer();
        updateObservers();
    }

    void Chess::nextPlayer()
    {
        if (currentPlayer == &players.first)
            currentPlayer = &players.second;
        else
            currentPlayer = &players.first;
    }
}