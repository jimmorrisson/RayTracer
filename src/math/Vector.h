#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    double x{};
    double y{};
    double z{};

public:
    constexpr Vector() noexcept = default;

    explicit Vector(const double x, const double y, const double z);

    Vector operator+(const Vector &vec) noexcept;

    Vector operator-(const Vector &vec) noexcept;

    Vector operator*(const double value) noexcept;

    double get_x() const noexcept;

    double get_y() const noexcept;

    double get_z() const noexcept;
};

#endif // VECTOR_H
