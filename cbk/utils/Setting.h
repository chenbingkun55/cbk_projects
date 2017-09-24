#pragma once

#include <BaseType.h>
#include <utils/NonCopyable.h>
#include <rapidjson/document.h>

using namespace rapidjson;

NS_BEGIN
class Setting : public NonCopyable
{
public:
    Setting();
    Setting(const std::string& filename);
    ~Setting();

    bool init(const std::string& filename);

private:
    bool parseSetting(const std::string& filename);

protected:
    Document m_document;
};
NS_END
