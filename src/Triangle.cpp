#include "Triangle.h"
#include <cmath>

bool Triangle::intersects(const Ray &ray, double &d)
{
    auto v0v1 = V1 - V0;
    auto v0v2 = V2 - V0;

    auto N = v0v1.cross_product(v0v2);

    auto NdotRayDirection = N.dot(ray.get_destination());
    if (std::fabs(NdotRayDirection) < 1e-4)
    {
        return false;
    }

    float t = N.dot(V0);
    d = (N.dot(ray.get_origin()) + t) / NdotRayDirection;

    if (d < 0) return false;

    auto P = ray.get_origin() + d * ray.get_destination();

    auto edge0 = V1 - V0;
    auto vp0 = P - V0;
    auto C = edge0.cross_product(vp0);
    if (N.dot(C) < 0) return false;

    auto edge1 = V2 - V1;
    auto vp1 = P - V1;
    auto D = edge1.cross_product(vp1);
    if (N.dot(D) < 0) return false;

    auto edge2 = V0 - V2;
    auto vp2 = P - V2;
    auto E = edge2.cross_product(vp2);
    if (N.dot(E) < 0) return false;

    return true;
}