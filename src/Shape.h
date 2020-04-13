#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "Color.h"

class Shape
{
protected:
    Color color{};

public:
    constexpr Shape() = default;

    explicit Shape(const Color color) :
        color { color }
    {
    }

    constexpr Shape(const Shape&) = delete;
    Shape& operator=(const Shape&) = delete;
    constexpr Shape(Shape&&) = delete;
    virtual ~Shape() = default;

    virtual bool intersects(const Ray& ray, double &d) = 0;

    virtual void set_color(const Color &color) = 0;

    constexpr Color get_color() const noexcept { return color; }
};

#endif // SHAPE_H
