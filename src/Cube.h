#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include "Ray.h"

class Cube : public Shape
{
public:
    virtual bool intersects(const Ray &ray, double &d) override;
};

#endif // CUBE_H
