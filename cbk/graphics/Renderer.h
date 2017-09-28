#pragma once 

#include <BaseType.h>
#include <core/Engine.h>

NS_BEGIN
namespace graphics
{
class Renderer : public NonCopyable
{
    friend Engine;
public:
    enum class Driver
    {
        Default,
        Empty,
        Opengl,
    };

public:
    Renderer() {};
    ~Renderer() {};
    
};
}
NS_END
