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

Vector Vector::operator-(const Vector &vec) const noexcept
{
    return Vector{ x - vec.x, y - vec.y, z - vec.z };
}

// template <typename T>
// Vector Vector::operator*(const T value) noexcept
// {
//     return Vector{ x * value, y * value, z * value };
// }

template <typename T>
Vector Vector::operator/(const T value) const noexcept
{
    return Vector{ x / value, y / value, z / value };
}

double Vector::dot(const Vector &vector) const noexcept
{
    return x * vector.x + y * vector.y + z * vector.z;
}

Vector Vector::cross_product(const Vector &vector) const noexcept
{
    Vector i{ 1, 0, 0 };
    Vector j{ 0, 1, 0 };
    Vector k{ 0, 0, 1 };

    return (x * vector.y * k) + 
           (y * vector.z * i) +
           (z * vector.x * j) -
           (z * vector.y * i) -
           (x * vector.z * j) -
           (y * vector.x * k);
}

double Vector::magnitude() const noexcept
{
    return std::sqrt( x * x + y * y + z * z );
}

Vector Vector::normalize() const noexcept
{
    return *this / magnitude();
}

void Vector::normalize() noexcept
{
    *this = *this / magnitude();
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

template <typename T>
Vector operator/(const T val, const Vector &vector)
{
    return Vector{ vector.x / val, vector.y / val, vector.z / val };
}
