#include <iostream>
#include <vector>
#include <fstream>

#include <math/Vector.h>
#include <Sphere.h>
#include <Functions.h>
#include <Cube.h>
#include <Plane.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  Vector center { 1, 2, 3 };
  Ray ray{ Vector{ 0, 0, 0 }, Vector{ 0, 0, 1 } };

  auto *sphere = new Sphere{ Vector{ 250, 250, 50 }, 50 };
  std::vector<Shape*> shapes{ new Sphere{ Vector{ 250, 250, 50 }, 50 }/*, new Cube{ }, new Plane{ Vector{ 0, 0, 1 }, Vector{ 0, 1, 0 } } */};

  const uint16_t width{ 500 };
  const uint16_t height{ 500 };

  std::ofstream out("out.ppm");
  out << "P3\n" << width << ' ' << height << ' ' << "255\n";
  
  for (size_t y = 0; y < height; y++)
  {
    for (size_t x = 0; x < width; x++)
    {
      const Ray ray{ Vector{ static_cast<double>(x), static_cast<double>(y), 0 },
                     Vector{ 0, 0, 1 }};
      double d { 0 };
      // Color pixel_color = Color::black;
      const auto intersects = RayTracer::intersects(sphere, ray, d);
      if (intersects)
      {
        auto text = Color::red.to_string();
        out << Color::red.to_string();
        continue;
        // if (pixel_color != Color::black)
        // {
        //   out << pixel_color.to_string();
        //   continue;
        // }
      }
      out << "0 0 0\n";
    }
  }

  
  return 0;
}
