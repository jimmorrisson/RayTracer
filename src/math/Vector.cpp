#include "Vector.h"

Vector::Vector(const double x, 
        const double y, const double z) :
        x{ x },
        y{ y },
        z{ z }
{
}

Vector Vector::operator+(const Vector &vec) noexcept
{
    return Vector{ x + vec.x, y + vec.y, z + vec.z };
}

Vector Vector::operator-(const Vector &vec) noexcept
{
    return Vector{ x - vec.x, y - vec.y, z - vec.z };
}

Vector Vector::operator*(const double value) noexcept
{
    return Vector{ x * value, y * value, z * value };
}

double Vector::get_x() const noexcept
{
    return x;
}

double Vector::get_y() const noexcept
{
    return y;
}

double Vector::get_z() const noexcept
{
    return z;
}