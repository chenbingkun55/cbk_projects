#pragma once

#include <BaseType.h>
#include <utils/NonCopyable.h>
#include <utils/Setting.h>
#include <files/FileSystem.h>
#include <window/Window.h>

void engineMain(const std::vector<std::string>& args);

NS_BEGIN
class Window;
class Engine : public NonCopyable
{
public:
    Engine();
    virtual ~Engine();

    bool init();
    void start();

    virtual int run();
    virtual void main();

    FileSystem* getFileSystem() { return m_fileSystem.get(); }
    Window* getWindow() { return m_window.get(); }

protected:
    bool m_bActive;
    bool m_bPaused;
    Setting m_defaultSetting;
    Setting m_userSetting;
    std::string m_graphicsDriver;

    std::vector<std::string> m_args;

    std::unique_ptr<FileSystem> m_fileSystem;
    std::unique_ptr<Window> m_window;
};

extern Engine* sharedEngine;

NS_END
