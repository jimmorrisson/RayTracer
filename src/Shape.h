#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"

class Shape
{
public:
    constexpr Shape() = default;
    constexpr Shape(const Shape&) = delete;
    constexpr Shape(Shape&&) = delete;
    virtual ~Shape() = default;
    virtual bool intersects(const Ray& ray, double &d) = 0;
};

#endif // SHAPE_H
