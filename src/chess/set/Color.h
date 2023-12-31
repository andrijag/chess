#ifndef COLOR_H
#define COLOR_H

namespace chess
{
    enum class Color
    {
        white,
        black
    };

    inline Color operator!(Color color)
    {
        return (color == Color::white) ? Color::black : Color::white;
    }
}

#endif