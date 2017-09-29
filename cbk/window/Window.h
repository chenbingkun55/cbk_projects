#pragma once

#include <BaseType.h>
#include <core/Engine.h>
#include <math/Size2.h>

NS_BEGIN
class Engine;

class Window : public NonCopyable
{
    friend Engine;
public:
    Window();
    virtual ~Window();

    virtual void close();
    virtual const Size2& getSize() const { return m_size; }


protected:
    Size2 m_size;

};

NS_END

