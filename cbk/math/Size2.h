#pragma once

#include <math/Vector2.h>

NS_BEGIN
class Size2
{
public:
    Size2()
    {
    }

    Size2(float w, float h)
        : width(w), height(h)
    {
        
    }

    Size2(const Vector2& point)
        : width(point.x), height(point.y)
    {
    
    }

    Size2& operator=(const Vector2& porint)
    {
        width = porint.x;
        height = porint.y;
        return *this;
    }

    Size2 operator+(const Size2& size) const
    {
        return Size2(width + size.width, height + size.height);
    }

    inline Size2& operator+=(const Size2& size)
    {
        width += size.width;
        height += size.height;
        return *this;
    }

    Size2 operator-(const Size2& size) const
    {
        return Size2(width - size.width, height - size.height);
    }

    inline Size2& operator-=(const Size2& size)
    {
        width -= size.width;
        height -= size.height;
        return *this;
    }

    Size2 operator*(float a) const
    {
        return Size2(width * a , height * a);
    }

    inline Size2& operator*=(float scalar)
    {
        width *= scalar;
        height *= scalar;
        return *this;
    }

    Size2 operator/(float a) const
    {
        return Size2(width / a , height / a);
    }

    inline Size2& operator/=(float scalar)
    {
        width /= scalar;
        height /= scalar;
        return *this;
    }

    inline bool operator==(const Size2& size) const
    {
        return width == size.width && height == size.height;
    }

    inline bool operator!=(const Size2& size) const 
    {
        return width != size.width || height != size.height;
    }

    bool isZero() const 
    {
        return width == 0.0f && height == 0.0f;
    }

    bool isOne() const
    {
        return width == 1.0f && height == 1.0f;
    }

    float area() const 
    {
        return width * height;
    }

    void scalar(float scalar)
    {
        width *= scalar;
        height *= scalar;
    }

    void scalar(const Vector2& scale)
    {
        width *= scale.x;
        height *= scale.y;
    }

public:
    float width{0.0f};
    float height{0.0f};
};

inline Size2 operator*(const Size2& size, const Vector2& v)
{
    return Size2(size.width * v.x, size.height * v.y);
}

inline Size2 operator/(const Size2& size, const Vector2& v)
{
    return Size2(size.width / v.x, size.height / v.y);
}

NS_END


