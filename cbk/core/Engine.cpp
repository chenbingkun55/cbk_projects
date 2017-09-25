#include "Engine.h"
#include "utils/Setting.h"
#if CBK_PLATFORM_LINUX
#include "files/linux/FileSystemLinux.h"
#elif CBK_PLATFORM_WINDOWS
#include "files/windows/FileSystemWin.h"
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

    m_defaultSetting.init("../setting.json");

    std::string name;
    m_defaultSetting.getValue(name, "app_name"); 

    int width;
    m_defaultSetting.getValue(width, "width"); 

    int panelWidth;
    m_defaultSetting.getValue(panelWidth, "width", "panel"); 

    int listWidth;
    m_defaultSetting.getValue(listWidth, "width", "list"); 

    int mapWidth;
    m_defaultSetting.getValue(mapWidth, "width", "map"); 

    int buttonWidth;
    m_defaultSetting.getValue(buttonWidth, "width", "button"); 

    std::cout << name << std::endl;
    std::cout << width << std::endl;
    std::cout << panelWidth << std::endl;
    std::cout << listWidth << std::endl;
    std::cout << mapWidth << std::endl;
    std::cout << buttonWidth << std::endl;
    /* m_userSetting.init("../setting.json"); */
    
    
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
