#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "math/Vector.h"

class Sphere : public Shape
{
    Vector center{};
    double radius{};
public:
    Sphere(const Vector &center, const double radius);

    double get_radius() const noexcept;

    bool intersects(const Ray &ray, double &d) override;
};

#endif // SPHERE_H
