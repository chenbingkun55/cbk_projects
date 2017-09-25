#pragma once

#include <sstream>

#include <BaseType.h>
#include <utils/NonCopyable.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using namespace rapidjson;

NS_BEGIN
class Setting : public NonCopyable
{
public:
    Setting();
    Setting(const std::string& filename);
    ~Setting();

    bool init(const std::string& filename);

    void setValue(const std::string& section, const std::string& key, const std::string& value);
    bool deleteValue(const std::string& section, const std::string& key);

    template <typename T>
    bool getValue(T& outData, const std::string& key, const std::string& item = EMPTY_STRING) const
    {
        Value::ConstMemberIterator itr = m_document.MemberEnd();

        if(item.empty())
        {
            itr = m_document.FindMember(key.c_str());
        }
        else
        {
            Value::ConstMemberIterator itemIt = m_document.FindMember(item.c_str());
            if(itemIt != m_document.MemberEnd() && itemIt->value.IsObject())
            {
                itr = itemIt->value.FindMember(key.c_str());
            }
            else
            {
                for (auto& m : m_document.GetObject())
                {
                    if (!m.value.IsObject()) continue;

                    Value::ConstMemberIterator itemIt = m.value.FindMember(item.c_str());
                    if(itemIt != m_document.MemberEnd() && itemIt->value.IsObject())
                    {
                        itr = itemIt->value.FindMember(key.c_str());
                    }
                }
            }

        }

        if (itr != m_document.MemberEnd())
        {
            rapidjson::StringBuffer  buffer;
            rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);

            itr->value.Accept(writer);
            std::stringstream ss(buffer.GetString());
            ss >> outData;

            return static_cast<bool>(ss); 
        }

        return false;
    }

private:
    bool parseSetting(const std::string& filename);

private:
    Document m_document;
};
NS_END
