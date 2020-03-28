#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <Sphere.h>
#include <Ray.h>

TEST_CASE("Line sphere intersects", "Does not intersect") 
{
    Ray ray{ Vector{ 0, 0, 0 }, Vector{ 0, 0, 1 } };
    Sphere sphere{ Vector{ 250, 250, 50 }, 50 };

    double d{ 0.0 };
    REQUIRE_FALSE(sphere.intersects(ray, d));
}

TEST_CASE("Sphere intersects", "Does intersect") 
{
    Ray ray{ Vector{ 241, 201, 0 }, Vector{ 0, 0, 1 } };
    Sphere sphere{ Vector{ 250, 250, 50 }, 50 };

    double d{ 0.0 };
    REQUIRE(sphere.intersects(ray, d));
}