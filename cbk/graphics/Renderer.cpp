#include "Renderer.h"

NS_BEGIN
namespace graphics
{
std::set<Renderer::Driver> Renderer::getAvailableRendererDrivers()
{
    static std::set<Renderer::Driver> m_availableDrivers;

    if(m_availableDrivers.empty())
    {
        m_availableDrivers.insert(Renderer::Driver::Empty);
        m_availableDrivers.insert(Renderer::Driver::Opengl);
        m_availableDrivers.insert(Renderer::Driver::Default);
    }

    return m_availableDrivers;
}
}
NS_END
