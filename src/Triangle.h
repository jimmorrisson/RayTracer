#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "math/Vector.h"

class Triangle : public Shape
{
    Vector V0{};
    Vector V1{};
    Vector V2{};

public:
    explicit Triangle(const Vector &v0, const Vector &v1, const Vector &v2, const Color color = Color::green) :
        Shape{ color },
        V0 { v0 },
        V1 { v1 },
        V2 { v2 }
    {
    }

    bool intersects(const Ray & ray, double &d) override;

    void set_color(const Color &color) override;
};

#endif // TRIANGLE_H
