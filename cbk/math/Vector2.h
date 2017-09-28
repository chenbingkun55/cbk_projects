#pragma once

#include <cstddef>
#include <cmath>
#include <BaseType.h>

NS_BEGIN
class Vector2
{
public:
    static const Vector2 ZERO;
    static const Vector2 ONE;

    Vector2()
    {
    }

    Vector2(float x, float y)
        : x(x), y(y)
    {
    }

    Vector2(const Vector2& copy)
        : x(copy.x), y(copy.y)
    {
    }

public:
    float x{0.0f};
    float y{0.0f};

};
NS_END
