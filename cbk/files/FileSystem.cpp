#include <sys/stat.h>

#include "FileSystem.h"

FileSystem::FileSystem()
{

}

FileSystem::~FileSystem()
{

}

std::string FileSystem::getDirectoryPart(const std::string& path)
{
    size_t pos = path.find_last_of("/\\");

    if (pos != std::string::npos)
    {
        return path.substr(0, pos);
    }

    return std::string();
}

std::string FileSystem::getExtensionPart(const std::string& path)
{
    size_t pos = path.find_last_of('.');

    if (pos != std::string::npos)
    {
        return path.substr(pos + 1);
    }

    return std::string();
}


std::string FileSystem::getFilenamePart(const std::string& path)
{
    size_t pos = path.find_last_of("/\\");
    if (pos != std::string::npos)
    {
        return path.substr(pos + 1);
    }
    else
    {
        return path;
    }
}

bool FileSystem::readFile(std::string& outData, const std::string& filename, bool searchResources/* = true */) const
{
         std::string path = getPath(filename, searchResources);

         if (path.empty())
         {
             std::cout << "Failed to find file " << filename << std::endl;
             return false;
         }
      
         std::ifstream file(path, std::ios::binary);
      
         if (!file)
         {
             std::cout << "Failed to open file " << path << std::endl;
             return false;
         }
      
         outData.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

         return true;
}

std::string FileSystem::getPath(const std::string& filename, bool searchResources) const
{
     if (!searchResources || isAbsolutePath(filename))
     {
         if (fileExists(filename))
         {
             return filename;
         }
     }
     else
     {
         std::string str = m_appPath + DIRECTORY_SEPARATOR + filename;

         if (fileExists(str))
         {
             return str;
         }
         else
         {
             /* for (const std::string& path : resourcePaths) */
             /* { */
             /*     if (isAbsolutePath(path)) // if resource path is absolute */
             /*     { */
             /*         str = path + DIRECTORY_SEPARATOR + filename; */
             /*     } */
             /*     else */
             /*     { */
             /*         str = appPath + DIRECTORY_SEPARATOR + path + DIRECTORY_SEPARATOR + filename; */
             /*     } */

             /*     if (fileExists(str)) */
             /*     { */
             /*         return str; */
             /*     } */
             /* } */
         }
     }

     return "";
}

bool FileSystem::isAbsolutePath(const std::string& path) const
{
     return !path.empty() && path[0] == '/';
}

bool FileSystem::fileExists(const std::string& filename) const
{
     struct stat buf;
     if (stat(filename.c_str(), &buf) != 0)
     {
         return false;
     }

     return (buf.st_mode & S_IFMT) == S_IFREG;
}

