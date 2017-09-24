#include "Setting.h"
#include <core/Engine.h>

NS_BEGIN
Setting::Setting()
{

}

Setting::Setting(const std::string& filename)
{
    parseSetting(filename);
}

Setting::~Setting()
{

}

bool Setting::init(const std::string& filename)
{
    return parseSetting(filename);
}

bool Setting::parseSetting(const std::string& filename)
{
    std::string strData;
    sharedEngine->getFileSystem()->readFile(strData, filename, false);

    m_document.Parse(strData.c_str());
    assert(m_document.IsObject());

    /*
    if (m_document.HasParseError()) {
        rapidjson::ParseErrorCode code = m_document.GetParseError();
        std::cout << code << std::endl;
        return false;
    }

    */

    return true;
}

NS_END
