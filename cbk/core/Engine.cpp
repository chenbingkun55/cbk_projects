#include "Engine.h"
#include <math/Size2.h>
#include <utils/Setting.h>
#include <graphics/Renderer.h>
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


    std::string test = "ABC"; std::string graphicsDriverValue;
    m_defaultSetting.getValue(graphicsDriverValue, "graphicsDriver", "engine", test); 

    bool i = true;
    bool j = false;
    m_defaultSetting.getValue(j, "bool", "engine", i); 

    std::cout << j << "xxxx" << graphicsDriverValue << " " << std::endl;


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
