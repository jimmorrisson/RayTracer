#include <iostream>
#include <vector>

#include <math/Vector.h>
#include <Sphere.h>
#include <Functions.h>
#include <Cube.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  Vector center { 1, 2, 3 };
  Ray ray{ Vector{ 0, 0, 0 }, Vector{ 0, 0, 1 } };

  std::vector<Shape*> shapes{ new Sphere{ Vector{ 250, 250, 50 }, 50 }, new Cube{ } };

  double d { 0 };
  for (auto *shape : shapes)
  {
    RayTracer::intersects(shape, ray, d);
  }

  std::cout << "Hello, world! \n";
  
  return 0;
}
