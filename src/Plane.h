#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"
#include "math/Vector.h"

class Plane : public Shape
{
    Vector p;
    Vector n;

public:
    constexpr Plane(const Vector &p, const Vector &n) :
        p{ p },
        n{ n }
    {
        color = Color::blue;
    }

    bool intersects(const Ray &ray, double &d) override;
};

#endif // PLANE_H
