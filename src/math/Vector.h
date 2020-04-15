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

    Vector operator-(const Vector &vec) const noexcept;

    bool operator<(const Vector &vec) const noexcept;

    template <typename T> 
    Vector& operator*=(const T &value) noexcept
    {
        x *= value;
        y *= value;
        z *= value;
        return *this;
    }

    template <typename T>
    Vector operator*(const T &value) const
    {
        return Vector{ x * value, y * value, z * value };
    }

    template <>
    Vector operator*(const Vector &v1) const
    {
        return Vector { x * v1.x, y * v1.y, z * v1.z };
    }

    template <typename T>
    Vector operator/(const T value) const noexcept;

    double dot(const Vector &vector) const noexcept;

    Vector cross_product(const Vector &vector) const noexcept;

    static constexpr double dot(const Vector &v1, const Vector &v2) noexcept
    { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

    double magnitude() const noexcept;

    [[nodiscard]] Vector normalize(const Vector &vec) noexcept;

    void normalize() noexcept;

    double get_x() const noexcept;

    double get_y() const noexcept;

    double get_z() const noexcept;

    friend Vector operator*(const double val, const Vector &vector);

    template <typename T>
    friend Vector operator/(const T val, const Vector &vector);

    static const Vector& zero()
    {
        static Vector v{ 0, 0, 0 };
        return v;
    }
};

#endif // VECTOR_H
