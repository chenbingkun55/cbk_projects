#include "Engine.h"
#include <math/Size2.h>
#include <utils/Setting.h>
#include <graphics/Renderer.h>
#include <texture/Texture.h>
#if CBK_PLATFORM_LINUX
#include <files/linux/FileSystemLinux.h>
#elif CBK_PLATFORM_WINDOWS
#include <files/windows/FileSystemWin.h>
#endif

NS_BEGIN

NS::Engine* sharedEngine = nullptr;

Engine::Engine()
    :m_bActive(false), m_bPaused(false)
{
    sharedEngine = this;
}

Engine::~Engine()
{
    sharedEngine = nullptr;
}

bool Engine::init()
{
#if CBK_PLATFORM_LINUX
    m_fileSystem.reset(new FileSystemLinux);
#elif CBK_PLATFORM_WINDOWS
    m_fileSystem.reset(new FileSystemWin);
#endif


    graphics::Renderer::Driver graphicsDriver = graphics::Renderer::Driver::Default; 

    m_defaultSetting.init("../setting.json");
    m_userSetting.init("../user_setting.json");

    std::string graphicsDriverValue;
    m_defaultSetting.getValue(graphicsDriverValue, "graphicsDriver", "engine"); 
    m_userSetting.getValue(graphicsDriverValue, "graphicsDriver", "engine", graphicsDriverValue); 

    if(!graphicsDriverValue.empty())
    {
        if (graphicsDriverValue == "default")
        {
            graphicsDriver = graphics::Renderer::Driver::Default;
        }
        else if (graphicsDriverValue == "empty")
        {
            graphicsDriver = graphics::Renderer::Driver::Empty;
        }
        else if (graphicsDriverValue == "opengl")
        {
            graphicsDriver = graphics::Renderer::Driver::Opengl;
        }
        else
        {
            std::cout << "graphics Driver not find" << std::endl;
            return false;
        }
    }

    std::string widthValue, heightValue;
    m_defaultSetting.getValue(widthValue, "width", "engine"); 
    m_userSetting.getValue(widthValue, "width", "engine", widthValue); 

    m_defaultSetting.getValue(heightValue, "height", "engine"); 
    m_userSetting.getValue(heightValue, "height", "engine", heightValue); 
    
    graphics::Texture::Filter textureFilter = graphics::Texture::Filter::Point;

    std::string textureFilterValue;
    m_defaultSetting.getValue(textureFilterValue, "textureFilter", "engine"); 
    m_userSetting.getValue(textureFilterValue, "textureFilter", "engine", textureFilterValue); 

    if(!textureFilterValue.empty())
    {
        if(textureFilterValue == "point")
        {
            textureFilter = graphics::Texture::Filter::Default;
        }
        else if(textureFilterValue == "linear")
        {
            textureFilter = graphics::Texture::Filter::Linear;
        }
        else
        {
            std::cout << "texture filter not find" << std::endl;
            return false;
        }
    }

    std::string fullscreenValue;
    m_defaultSetting.getValue(fullscreenValue, "fullscree", "engine"); 
    m_userSetting.getValue(fullscreenValue, "fullscreen", "engine", fullscreenValue);

    if (graphicsDriver == graphics::Renderer::Driver::Default)
    {
        auto availableDrivers = graphics::Renderer::getAvailableRendererDrivers();

        if(availableDrivers.find(graphics::Renderer::Driver::Opengl) != availableDrivers.end())
        {
            graphicsDriver = graphics::Renderer::Driver::Opengl;
        }
        else
        {
            graphicsDriver = graphics::Renderer::Driver::Empty;
        }
    }

#if CBK_PLATFROM_LINUX
    m_window.reset(new WindowLinux);
#elif CBK_PLATFROM_WINDOWS
    m_window.reset(new WindowWin);
#else
    m_window.reset(new Window);
#endif
    
    std::cout << fullscreenValue << std::endl;

    return true;
}

void Engine::start()
{
    if (!m_bActive)
    {
        m_bActive = true;
        m_bPaused = false;

        main();
    }
}

int Engine::run()
{
    return EXIT_SUCCESS;
}

void Engine::main()
{
    engineMain(m_args);
}

NS_END
