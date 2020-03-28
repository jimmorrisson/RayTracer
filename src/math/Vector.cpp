#include "Vector.h"
#include <cmath>

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

template <typename T>
Vector Vector::operator*(const T value) noexcept
{
    return Vector{ x * value, y * value, z * value };
}

double Vector::dot(const Vector &vector) const noexcept
{
    return x * vector.x + y * vector.y + z * vector.z;
}

double Vector::magnitude() const noexcept
{
    return std::sqrt( x * x + y * y + z * z );
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

template <typename T>
Vector operator*(const T val, const Vector &vector)
{
    return Vector{ vector.x * val, vector.y * val, vector.z * val };
}