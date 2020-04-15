#include "Plane.h"
#include <cmath>

Plane::Plane(const Vector &point, const Vector &normal, const Color &color) :
    Shape{ color },
    point{ point },
    normal{ normal }
{

}

bool Plane::intersects(const Ray &ray, double &d)
{
    // const auto direction_dot_n = Vector::dot(ray.get_destination(), n);
    const auto denom = normal.dot(ray.get_destination());
    constexpr auto epsilon = 1e-5;

    if (std::abs(denom) > epsilon)
    {
        d = (point - ray.get_origin()).dot(normal) / denom;
        if (d >= 0 )
        {
            return true;
        }
    }

    return false;
}

void Plane::set_color(const Color &color)
{
    this->color = color;
}