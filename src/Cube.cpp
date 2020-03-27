#include "Cube.h"

#include <iostream>

bool Cube::intersects(const Ray &ray, double &d)
{
    std::cout << "Cube intersects\n";
    
    d = 1;

    if (ray.get_destination().get_x() < 1)
        return true;
    
    return false;
}