#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "math/Vector.h"

class Color;

class Sphere : public Shape
{
    Vector center{};
    double radius{};
public:
    Sphere(const Vector &center, const double radius, const Color color = Color::red);

    double get_radius() const noexcept;

    bool intersects(const Ray &ray, double &d) override;

    void set_color(const Color &color) override;

    const Vector& get_center() const 
    { return center; }
};

#endif // SPHERE_H
