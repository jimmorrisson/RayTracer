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

    template <typename T>
    Vector operator*(const T value) noexcept;

    double dot(const Vector &vector) const noexcept;

    static constexpr double dot(const Vector &v1, const Vector &v2) noexcept
    { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

    double magnitude() const noexcept;

    double get_x() const noexcept;

    double get_y() const noexcept;

    double get_z() const noexcept;

    template <typename T>
    friend Vector operator*(const T val, const Vector &vector);
};

#endif // VECTOR_H
