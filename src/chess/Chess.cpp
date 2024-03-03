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
        boardSetup();
    }

    void Chess::move(Position from, Position to)
    {
        if (!isLegalMove(from, to))
            return;

        moveChessPiece(board, from, to);

        if (isStalemate(!currentPlayer->getColor()))
        {
            clock.stop();
            state = GameState::stalemate;
        }
        else if (isCheckmated(!currentPlayer->getColor()))
        {
            clock.stop();
            state = (currentPlayer->getColor() == Color::white) ? GameState::whiteCheckmates : GameState::blackCheckmates;
        }
        else
        {
            currentPlayer->stopTime(clock);
            nextPlayer();
        }

        updateObservers();
    }

    void Chess::restart()
    {
        clock = ChessClock{};
        board = Chessboard{};
        currentPlayer = &players.first;
        state = GameState::playing;
        boardSetup();
    }

    void Chess::boardSetup()
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

    bool Chess::isLegalMove(Position from, Position to) const
    {
        return state == GameState::playing &&
               currentPlayer->isOwnPieceAt(board, from) &&
               getPossibleMoves(from).contains(to);
    }

    void Chess::nextPlayer()
    {
        if (currentPlayer == &players.first)
            currentPlayer = &players.second;
        else
            currentPlayer = &players.first;
    }

    bool Chess::isStalemate(Color color) const
    {
        return !isInCheck(board, color) && !hasPossibleMoves(color);
    }

    bool Chess::isCheckmated(Color color) const
    {
        return isInCheck(board, color) && !hasPossibleMoves(color);
    }

    bool Chess::hasPossibleMoves(Color color) const
    {
        for (auto row = 0; row < board.getNumberOfRows(); row++)
            for (auto column = 0; column < board.getNumberOfColumns(); column++)
            {
                Position square{row, column};
                if (!board.isEmptyAt(square) && board.getChessPieceAt(square)->getColor() == color && !getPossibleMoves(square).empty())
                    return true;
            }
        return false;
    }

    std::unordered_set<Position> Chess::getPossibleMoves(Position from) const
    {
        std::unordered_set<Position> possibleMoves;
        auto movePattern = board.getChessPieceAt(from)->getMovePattern(board, from);
        for (auto move : movePattern)
        {
            auto boardCopy = board;
            moveChessPiece(boardCopy, from, move);
            if (!isInCheck(boardCopy, board.getChessPieceAt(from)->getColor()))
                possibleMoves.insert(move);
        }
        return possibleMoves;
    }

    void moveChessPiece(Chessboard &board, Position from, Position to)
    {
        board.move(from, to);
        if (auto pawn = dynamic_cast<Pawn *>(board.getChessPieceAt(to)))
            pawn->setFirstMove(false);
    }

    bool isInCheck(const Chessboard &board, Color color)
    {
        for (auto square : getSquaresUnderAttack(board, !color))
            if (!board.isEmptyAt(square) && dynamic_cast<King *>(board.getChessPieceAt(square)))
                return true;
        return false;
    }

    std::unordered_set<Position> getSquaresUnderAttack(const Chessboard &board, Color color)
    {
        std::unordered_set<Position> squaresUnderAttack;
        for (auto row = 0; row < board.getNumberOfRows(); row++)
            for (auto column = 0; column < board.getNumberOfColumns(); column++)
            {
                Position square = {row, column};
                if (!board.isEmptyAt(square) && board.getChessPieceAt(square)->getColor() == color)
                {
                    auto movePattern = board.getChessPieceAt(square)->getMovePattern(board, square);
                    squaresUnderAttack.merge(movePattern);
                }
            }
        return squaresUnderAttack;
    }
}