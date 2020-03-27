#ifndef RAY_H
#define RAY_H

#include "math/Vector.h"

class Ray
{
private:
    Vector origin{};
    Vector destination{};

public:
    explicit Ray(const Vector origin, const Vector destination);

    Vector get_origin() const noexcept;

    Vector get_destination() const noexcept;
};

#endif // RAY_H
