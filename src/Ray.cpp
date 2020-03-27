#include "Ray.h"

Ray::Ray(const Vector origin, const Vector destination) :
    origin{ origin },
    destination{ destination }
{

}

Vector Ray::get_origin() const noexcept
{
    return origin;
}

Vector Ray::get_destination() const noexcept
{
    return destination;
}