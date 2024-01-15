#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>

#include "Position.h"

namespace chess
{
    namespace direction
    {
        constexpr Position n{-1, 0};
        constexpr Position ne{-1, 1};
        constexpr Position e{0, 1};
        constexpr Position se{1, 1};
        constexpr Position s{1, 0};
        constexpr Position sw{1, -1};
        constexpr Position w{0, -1};
        constexpr Position nw{-1, -1};

        constexpr int numberOfDirections{8};
        constexpr std::array<Position, numberOfDirections> directions{
            direction::n,
            direction::ne,
            direction::e,
            direction::se,
            direction::s,
            direction::sw,
            direction::w,
            direction::nw};
    }
}

#endif