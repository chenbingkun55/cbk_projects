#include "EngineLinux.h"

EngineLinux::EngineLinux(int aArgc, char* aArgv[])
{
    for (int i = 0; i < aArgc; ++i)
    {
        m_args.push_back(aArgv[i]);
     }
}

EngineLinux::~EngineLinux()
{

}

int EngineLinux::run()
{
    if (!init())
    {
        return EXIT_FAILURE;
    }

    start();

    return EXIT_SUCCESS;
}
