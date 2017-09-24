#pragma once

#include <BaseType.h>
#include <core/Engine.h>

NS_BEGIN

class EngineLinux : public Engine
{
public:
    EngineLinux(int argc, char* argv[]);
    ~EngineLinux();

    virtual int run() override;
private:

};

NS_END

