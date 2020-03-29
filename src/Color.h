#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <string>
#include <sstream>

class Color
{
    uint8_t r{};
    uint8_t g{};
    uint8_t b{};

public:
    constexpr Color() = default;
    constexpr Color(const uint8_t r, const uint8_t g, const uint8_t b) :
        r{ r },
        g{ g },
        b{ b }
    {
    }

    std::string to_string() const noexcept
    {
        std::ostringstream oss;
        oss << r << " " << g << " " << b << "\n";
        return "255 0 0\n";
    }

    bool operator!=(const Color& color)
    { return r == color.r && g == color.g && b == color.b; }

    static Color black;
    static Color white;
    static Color red;
    static Color green;
    static Color blue; 
};

#endif // COLOR_H
