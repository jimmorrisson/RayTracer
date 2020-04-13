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

    Color& operator=(const Color& color)
    {
        this->r = color.r;
        this->g = color.g;
        this->b = color.b;
        return *this;
    }

    Color operator+(const Color &color)
    {
        return Color{ 
            static_cast<uint8_t>(r + color.r), 
            static_cast<uint8_t>(g + color.g), 
            static_cast<uint8_t>(b + color.b) };
    }

    std::string to_string() const noexcept
    {
        std::ostringstream oss;
        oss << std::to_string(r) << " " << std::to_string(g) << " " << std::to_string(b) << "\n";
        return oss.str();
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
