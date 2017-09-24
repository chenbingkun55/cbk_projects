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
    m_defaultSetting = new Setting();

    m_defaultSetting->init("../setting.json");
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
