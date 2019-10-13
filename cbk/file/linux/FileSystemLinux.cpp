#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>

#include "FileSystemLinux.h"

NS_BEGIN

static char TEMP_BUFFER[1024];
FileSystemLinux::FileSystemLinux()
{
     if (readlink("/proc/self/exe", TEMP_BUFFER, sizeof(TEMP_BUFFER)) != -1)
     {                
         m_appPath = getDirectoryPart(TEMP_BUFFER);
     }                
     else             
     {                
         std::cout << "Failed to get current directory" << std::endl;
     }
}

FileSystemLinux::~FileSystemLinux()
{

}

void FileSystemLinux::printFs()
{
    std::cout << "Files FsLinux. " + DIRECTORY_SEPARATOR << std::endl;
}

   /* FileSystemLinux::FileSystemLinux() */                                                                          
   /*   { */
   /*       if (readlink("/proc/self/exe", TEMP_BUFFER, sizeof(TEMP_BUFFER)) != -1) */
   /*       { */
   /*           appPath = getDirectoryPart(TEMP_BUFFER); */
   /*       } */
   /*       else */
   /*       { */
   /*           Log(Log::Level::ERR) << "Failed to get current directory"; */
   /*       } */
   /*   } */

NS_END
