#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <memory>

#include "Shape.h"
#include "Ray.h"

namespace RayTracer
{

bool intersects(Shape *shape, const Ray &ray, double &d)
{
    shape->intersects(ray, d);
    return true;
}

}

#endif // FUNCTIONS_H
