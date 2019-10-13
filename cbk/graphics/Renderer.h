#pragma once 
#include <set>
#include <BaseType.h>
#include <utils/NonCopyable.h>

NS_BEGIN
class Engine;

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
    ~Renderer() {};
    
    static std::set<Renderer::Driver> getAvailableRendererDrivers();

protected:
    Renderer(Driver driver);
};
}
NS_END
