#pragma once

#include <BaseType.h>
#include <utils/NonCopyable.h>
#include <utils/Setting.h>
#include <files/FileSystem.h>

void engineMain(const std::vector<std::string>& args);

NS_BEGIN
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

protected:
    bool m_bActive;
    bool m_bPaused;
    Setting* m_defaultSetting;
    Setting* m_userSetting;

    std::vector<std::string> m_args;

    std::unique_ptr<FileSystem> m_fileSystem;
};

extern Engine* sharedEngine;

NS_END
