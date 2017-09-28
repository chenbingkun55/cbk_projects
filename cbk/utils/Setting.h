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
    bool getValue(T& outData, const std::string& key, const std::string& item = EMPTY_STRING, T& defaultValue = static_cast<T>(0)) const
    {
        Value::ConstMemberIterator itr = m_document.FindMember(key.c_str());
        Value::ConstMemberIterator itemIt = m_document.MemberEnd();

        if( itr == m_document.MemberEnd() && !item.empty())
        {
            itemIt = m_document.FindMember(item.c_str());
            if(itemIt != m_document.MemberEnd() && itemIt->value.IsObject())
            {
                itr = itemIt->value.FindMember(key.c_str());
            }
            else
            {
                for (auto& m : m_document.GetObject())
                {
                    if (m.value.IsObject() && m.value.GetString() == item)
                    {
                        itr = itemIt->value.FindMember(key.c_str());
                    }
                }
            }
        }

        if (itr != itemIt->value.MemberEnd())
        {
            std::stringstream ss;
            if(itr->value.IsString())
            {
                ss << itr->value.GetString();
            } 
            else if (itr->value.IsInt())
            {
                ss << itr->value.GetInt();
            }
            else if (itr->value.IsBool())
            {
                ss << std::boolalpha << itr->value.GetBool();
            }
            else
            {
                std::cout << "value is not find type." << std::endl;
            }

            ss >> std::boolalpha >> outData; //boolalpha将bool解释为 false, ture 
            return static_cast<bool>(ss);
        } 
        else
        {
            outData = defaultValue;
            return false;
        }

        return false;
    }

private:
    bool parseSetting(const std::string& filename);

private:
    Document m_document;
};
NS_END
