#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include <math/Vector.h>
#include <Sphere.h>
#include <Functions.h>
#include <Cube.h>
#include <Plane.h>
#include <Triangle.h>


Color trace(const Ray &ray, const std::vector<Shape*> &shapes, double &d, [[maybe_unused]] uint8_t &recursion_counter, [[maybe_unused]] uint8_t max_recursion_counter);

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  Vector center { 1, 2, 3 };
  Ray ray{ Vector{ 0, 0, 0 }, Vector{ 0, 0, 1 } };

  // Triangle triangle{ Vector{ 100, 200, 50 }, Vector{ 200, 200, 50 }, Vector{ 150, 300, 50 } } ;
  Sphere sphere1{ Vector{ 250, 250, 50 }, 50 };
  Sphere sphere{ Vector{ 100, 250, 50 }, 50, Color::blue };
  auto plane_normal = Vector{ 0, 10, -1 };
  plane_normal.normalize();
  Plane plane{ Vector{ 250, 50, 50 }, plane_normal, Color{ 168, 168, 168 } };
  // Triangle triangle1{ Vector{ 300, 200, 50 }, Vector{ 400, 200, 50 }, Vector{ 350, 300, 50 } } ;
  std::vector<Shape*> shapes{ &sphere1, &sphere, &plane };

  const uint16_t width{ 500 };
  const uint16_t height{ 500 };
  const uint8_t max_recursion_count{ 3 };

  std::ofstream out("out.ppm");
  out << "P3\n" << width << ' ' << height << ' ' << "255\n";
  
  for (size_t y = 0; y < height; y++)
  {
    for (size_t x = 0; x < width; x++)
    {
      const Ray ray{ Vector{ static_cast<double>(x), static_cast<double>(y), 0 },
                     Vector{ 0, 0, 1 }};
      double d{ 0 };
      uint8_t recursion_counter{ 0 };
      const auto pixel_color = trace(ray, shapes, d, recursion_counter, max_recursion_count);
      out << pixel_color.to_string();
    }
  }

  return 0;
}

Color trace(const Ray &ray, const std::vector<Shape*> &shapes, double &d, [[maybe_unused]] uint8_t &recursion_counter, [[maybe_unused]] uint8_t max_recursion_counter = 3)
{
  Color pixel_color = Color::black;
  Color reflection_color = Color::black;
  
  for (auto *shape : shapes)
  {
    const auto intersects = RayTracer::intersects(shape, ray, d);
  
    //BEGINNING OF REFLECTION CODE
    //point of intersection
    auto hit_point = ray.get_origin() + d * ray.get_destination();
    auto sphere = dynamic_cast<Sphere*>(shape);
    if (intersects
        && sphere != nullptr
        && recursion_counter < max_recursion_counter)
    {
      //normal at the intersection point
      //normalize the vector direction
      auto normal_hit = hit_point - sphere->get_center();
      normal_hit.normalize();
      // compute reflection direction (not need to normalize because all vectors
      // are already normalized)
      auto reflection_direction = ray.get_destination() - normal_hit * 2 * ray.get_destination().dot(normal_hit);
      reflection_direction.normalize(); 
      const auto reflection_origin = hit_point + normal_hit;
      const Ray reflection_ray{ reflection_origin, reflection_direction };
      recursion_counter++;
      reflection_color = trace(reflection_ray, shapes, d, recursion_counter, max_recursion_counter);
    }
    //END OF REFLECTION CODE

    if (intersects)
    {
      pixel_color = shape->get_color();
      break;
    }
  }

  std::string filename{ "reflection.txt" };
  std::ofstream file_stream{ filename, std::ios::out | std::ios::app };
  if (!file_stream.is_open())
  {
    std::cout << "Failed to open reflection.txt" << std::endl;
  }
  else
  {
    file_stream << "Reflects: " << reflection_color.to_string() << std::endl;
  }
  
  return pixel_color + reflection_color;
} 