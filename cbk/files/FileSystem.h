#pragma once

#include <BaseType.h>
#include <utils/NonCopyable.h>

NS_BEGIN
class FileSystem : public NonCopyable
{
public:
#if CBK_PLATFORM_WINDOWS                                                  
    const std::string DIRECTORY_SEPARATOR = "\\";
#else
    const std::string DIRECTORY_SEPARATOR = "/";
#endif

public:
    virtual ~FileSystem();

    void printWorld();
    virtual void printFs() { std::cout << "Test FS" << std::endl; };

    static std::string getDirectoryPart(const std::string& path);
    static std::string getFilenamePart(const std::string& path);
    static std::string getExtensionPart(const std::string& path);

    virtual bool readFile(std::string& outData, const std::string& filename, bool searchResources = true) const;
    std::string getPath(const std::string& filename, bool searchResources = true) const;

    virtual bool isAbsolutePath(const std::string& path) const;
    virtual bool fileExists(const std::string& filename) const;

protected:
    FileSystem();

    std::string m_appPath;

};
NS_END
