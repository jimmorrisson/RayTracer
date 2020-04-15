#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"
#include "math/Vector.h"

class Plane : public Shape
{
    // Plane is defined by a point on the surface and the normal of Plane 
    Vector point; 
    Vector normal;

public:
    explicit Plane(const Vector &point, const Vector &normal, const Color &color = Color::blue);

    bool intersects(const Ray &ray, double &d) override;

    void set_color(const Color &color) override;
};

#endif // PLANE_H
