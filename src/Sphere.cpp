#include "Sphere.h"

#include <iostream>
#include <cmath>

Sphere::Sphere(const Vector &center, const double radius) :
    center{ center },
    radius{ radius }
{

}

double Sphere::get_radius() const noexcept
{
    return radius;
}

bool Sphere::intersects(const Ray &ray, double &d)
{
    const auto os = ray.get_origin() - center;

    // For delta equation
    const auto b = 2 * ray.get_destination().dot(os);
    const auto c = Vector::dot(os, os) - radius * radius;

    const auto delta = b * b - 4 * c;
    if (delta < 1e-4) return false;
    const auto delta_sqrt = std::sqrt( delta );
    const auto d1 = ( -b - delta_sqrt ) / 2;
    const auto d2 = ( -b + delta_sqrt ) / 2;    

    d = (d1 > d2) ? d1 : d2;
    return true;
}