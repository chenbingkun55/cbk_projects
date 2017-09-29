#pragma once

#include <BaseType.h>

NS_BEGIN
namespace graphics
{
class Texture : public NonCopyable
{
public:
    enum class Filter
    {
        Default,
        Point,
        Linear,
        Bilnear,
        Trilinear 
    };

    Texture();
    ~Texture();

public:

};
}
NS_END
