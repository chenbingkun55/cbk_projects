#pragma once 
#include <set>
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
    
    static std::set<Renderer::Driver> getAvailableRendererDrivers();
};
}
NS_END
