#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <math/Vector.h>

TEST_CASE("Initial test", "Initial") 
{
    Vector vec{ 0, 0, 0 };
    REQUIRE_FALSE(vec.magnitude() != 0);
}