#ifndef POSITION_H
#define POSITION_H

#include <cstddef>
#include <functional>

namespace chess
{
    struct Position
    {
        int row{};
        int column{};
    };

    inline Position &operator+=(Position &a, const Position &b)
    {
        a.row += b.row;
        a.column += b.column;
        return a;
    }

    inline Position &operator-=(Position &a, const Position &b)
    {
        a.row -= b.row;
        a.column -= b.column;
        return a;
    }

    inline Position operator+(const Position &a)
    {
        return {a.row, a.column};
    }

    inline Position operator-(const Position &a)
    {
        return {-a.row, -a.column};
    }

    inline Position operator+(const Position &a, const Position &b)
    {
        return {a.row + b.row, a.column + b.column};
    }

    inline Position operator-(const Position &a, const Position &b)
    {
        return {a.row - b.row, a.column - b.column};
    }

    inline bool operator==(const Position &a, const Position &b)
    {
        return a.row == b.row && a.column == b.column;
    }

    inline bool operator!=(const Position &a, const Position &b)
    {
        return !(a == b);
    }
}

template <>
struct std::hash<chess::Position>
{
    std::size_t operator()(const chess::Position &p) const
    {
        return std::hash<int>()(p.row) ^ std::hash<int>()(p.column);
    }
};

#endif