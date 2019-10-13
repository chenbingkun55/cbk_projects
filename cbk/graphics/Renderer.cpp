#include "Renderer.h"

NS_BEGIN
namespace graphics
{
Renderer::Renderer(Driver driver)
{
    switch(driver)
    {
#if CBK_COMPLE_OPENGL
        case graphics::Renderer::Driver::Opengl: 
            Log(Log::Level::INFO) << "Using OpenGL render driver";
#if CBK_PLATFORM_LINUX
            m_device.reset(new graphics::RenderDeviceOGLLinux());
#endif
        break;
#endif
        case graphics::Renderer::Driver::Empty: 
        break;
        default:
        break;
    }
}

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
