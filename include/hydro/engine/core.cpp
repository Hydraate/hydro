//
//                 __  __            __           
//                / / / /__  __ ____/ /_____ ____ 
//               / /_/ // / / // __  // ___// __ \
//              / __  // /_/ // /_/ // /   / /_/ /
//             /_/ /_/ \__, / \__,_//_/    \____/ 
//                    /____/                      
//
//              The Hydro Programming Language
//

#include "core.hpp"

namespace hydro::engine
{
/**
 *
 */
Boolean::Boolean()
{
    mValue = false;
}

/**
 *
 */
Boolean::Boolean(bool value)
{
    mValue = value;
}

/**
 *
 */
Boolean::Boolean(const Boolean &_bool)
{
    mValue = _bool.mValue;
}

/**
 *
 */
Boolean::Boolean(Boolean &&_bool)
{
    mValue = _bool.mValue;
}

/**
 *
 */
Boolean::~Boolean()
{
}

/**
 *
 */
Boolean &
Boolean::operator=(const Boolean &rhs)
{
    mValue = rhs.mValue;
    return (*this);
}

/**
 *
 */
Boolean &
Boolean::operator=(Boolean &&rhs)
{
    mValue = rhs.mValue;
    return (*this);
}

/**
 *
 */
Number::Number()
{
    mValue = 0.0;
}

Number::Number(double value)
{
    mValue = value;
}

Number::Number(const Number &number)
{
    mValue = number.mValue;
}

Number::Number(Number &&number)
{
    mValue = number.mValue;
}

Number::~Number()
{
}

Number &
Number::operator=(const Number &rhs)
{
    mValue = rhs.mValue;
    return (*this);
}

Number &
Number::operator=(Number &&rhs)
{
    mValue = rhs.mValue;
    return (*this);
}

/**
 *
 */
Color::Color()
{
    mValue = 0;
}

/**
 *
 */
Color::Color(Number value)
{
    mValue = value;
}

/**
 *
 */
Color::Color(Number r, Number g, Number b, Number a)
{
    uint8_t red = r;
    uint8_t green = g;
    uint8_t blue = b;
    uint8_t alpha = a;
    mValue = (double)((red << 24) + (green << 16) + (blue << 8) + (alpha));
}

/**
 *
 */
Color::Color(const Color &color)
{
    mValue = color.mValue;
}

/**
 *
 */
Color::Color(Color &&color)
{
    mValue = color.mValue;
}

/**
 *
 */
Color::~Color()
{
}

Number
Color::getRed() const
{
    uint64_t value = (uint64_t)mValue.valueOf() >> 24 & 0xFF;
    return (double)value;
}

Number
Color::getGreen() const
{
    uint64_t value = (uint64_t)mValue.valueOf() >> 16 & 0xFF;
    return (double)value;
}

Number
Color::getBlue() const
{
    uint64_t value = (uint64_t)mValue.valueOf() >> 8 & 0xFF;
    return (double)value;
}

Number
Color::getAlpha() const
{
    uint64_t value = (uint64_t)mValue.valueOf() & 0xFF;
    return (double)value;
}

Number
Color::valueOf() const
{
    return mValue;
}

Color &
Color::operator=(const Color &color)
{
    mValue = color.mValue;
    return (*this);
}

Color &
Color::operator=(Color &&color)
{
    mValue = color.mValue;
    return (*this);
}

/**
 *
 */
String::String()
{
}

/**
 *
 */
String::String(const char *)
{
}

/**
 *
 */
String::String(const String &string)
{
}

/**
 *
 */
String::String(String &&string)
{
}

/**
 *
 */
String::~String()
{
}

/**
 *
 */
Any::Any()
    //: mContent{ new holder<undefined_t>{ undefined } }
{
}

/**
 *
 */
Any::Any(undefined_t)
{
}

/**
 *
 */
Any::Any(std::nullptr_t)
{
}

/**
 *
 */
Any::Any(Boolean _bool)
{
}

/**
 *
 */
Any::Any(Color color)
{
}

/**
 *
 */
Any::Any(String string)
{
}

/**
 *
 */
Any::Any(Number number)
{
}

/**
 *
 */
Any::Any(object_ptr<HElement> object)
{
}

/**
 *
 */
Any::Any(const Any &any)
    : mContent{any.mContent->clone()}
{
}

/**
 *
 */
Any::Any(Any &&any)
{
}

/**
 *
 */
Any::~Any()
{
}

/**
 *
 */
bool Any::isNull() const
{
    return type() == typeid(std::nullptr_t);
}

/**
 *
 */
bool Any::isUndefined() const
{
    return type() == typeid(undefined_t);
}

/**
 *
 */
bool Any::isBoolean() const
{
    return type() == typeid(Boolean);
}

/**
 *
 */
bool Any::isColor() const
{
    return type() == typeid(Color);
}

/**
 *
 */
bool Any::isNumber() const
{
    return type() == typeid(Number);
}

/**
 *
 */
bool Any::isString() const
{
    return type() == typeid(Number);
}

/**
 *
 */
Any::operator bool() const
{
    if (isBoolean())
        return (Boolean)(*this);
    else if (isString())
        return (String)(*this);
    else if (isNumber())
        return (double)(Number)(*this) != 0;
    else if (isNull() || isUndefined())
        return false;
    else if (isColor())
        return true;
    return false;
}

/**
 *
 */
Any &Any::operator=(const Any &rhs)
{
    mContent = std::unique_ptr<placeholder>{rhs.mContent->clone()};
    return (*this);
}

/**
 *
 */
Any &Any::operator=(Any &&rhs)
{
    mContent = std::unique_ptr<placeholder>{rhs.mContent->clone()};
    return (*this);
}

} // namespace hydro::engine
