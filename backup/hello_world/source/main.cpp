#include <BaseType.h>
#include <core/Engine.h>

void engineMain(const std::vector<std::string>& args)
{
    NS::sharedEngine->getFileSystem()->printFs();
    std::cout << NS::FileSystem::getDirectoryPart("/tmp/a.txt") << std::endl;
}
