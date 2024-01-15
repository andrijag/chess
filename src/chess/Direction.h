#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>

#include "Position.h"

namespace chess
{
    using Direction = Position;

    namespace direction
    {
        constexpr Direction n{-1, 0};
        constexpr Direction ne{-1, 1};
        constexpr Direction e{0, 1};
        constexpr Direction se{1, 1};
        constexpr Direction s{1, 0};
        constexpr Direction sw{1, -1};
        constexpr Direction w{0, -1};
        constexpr Direction nw{-1, -1};
    }
}

#endif