#ifndef RELATIVE_VALUES_H
#define RELATIVE_VALUES_H

#include <limits>

namespace chess
{
    namespace fisher
    {
        constexpr double pawnValue{1};
        constexpr double knightValue{3};
        constexpr double bishopValue{3.25};
        constexpr double rookValue{5};
        constexpr double queenValue{9};
        constexpr double kingValue{std::numeric_limits<double>::infinity()};
    }
}

#endif