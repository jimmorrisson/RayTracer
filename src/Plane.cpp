#include "Plane.h"

bool Plane::intersects(const Ray &ray, double &d)
{
    const auto direction_dot_n = Vector::dot(ray.get_destination(), n);
    if (direction_dot_n == 0)
    {
        return false;
    }

    d = (Vector::dot(ray.get_origin(), n) - Vector::dot(p, n)) / direction_dot_n;

    return true;
}