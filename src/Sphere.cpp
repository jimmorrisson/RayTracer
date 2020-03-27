#include "Sphere.h"

#include <iostream>

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
    std::cout << "Sphere intersects\n";
    
    d = 1;

    if (ray.get_destination().get_x() < 1)
        return true;
    
    return false;
}