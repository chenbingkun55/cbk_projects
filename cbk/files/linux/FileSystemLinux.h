#include <files/FileSystem.h>

NS_BEGIN
class FileSystemLinux : public FileSystem
{
public:
    FileSystemLinux();
    ~FileSystemLinux();

    virtual void printFs() override;

private:

};
NS_END
