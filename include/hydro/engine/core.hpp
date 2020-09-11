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

#ifndef __h3o_engine_core__
#define __h3o_engine_core__

#include <cstdlib>
#include <memory>
#include <typeinfo>

#include "../system/HElement.hpp"
#include "../vm/hvalue.hpp"

namespace hydro::engine
{
class Any;
class Boolean;
class Color;
class String;
class Number;

/**
 * The Boolean class represents a primitive boolean value type. This class wraps the standard C bool type.
 */
class Boolean final
{
public:
    /**
     * Creates a false Boolean object.
     */
    Boolean();

    /**
     * Creates a Boolean object
     */
    Boolean(bool value);

    /**
     * Creates a copy of a Boolean object using value semantics.
     */
    Boolean(const Boolean &_bool);

    /**
     * Creates a copy of a Boolean object using move semantics.
     */
    Boolean(Boolean &&_bool);

    /**
     * Destroys the Boolean object.
     */
    ~Boolean();

    /**
     * Gets the standard C bool type that represents the value of the Boolean object.
     * @return Returns the standard C bool value that is wrapped by the Boolean object.
     */
    bool valueOf() const { return mValue; }

    /**
     * Evaluates the Boolean object as "truthy".
     * @return Returns true if the boolean is true. Otherwise returns false.
     */
    operator bool() const { return mValue; }

    /**
     * Evaluates the Boolean object as not "truthy".
     * @return Returns true if the boolean is false. Otherwise returns false.
     */
    bool operator!() const { return !mValue; }

    /**
     * Sets the boolean equal to another using value semantics.
     * @param rhs The right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    Boolean &operator=(const Boolean &rhs);

    /**
     * Sets the boolean equal to another using move semantics.
     * @param rhs The right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    Boolean &operator=(Boolean &&rhs);

private:
    /**
     * The value of the boolean.
     */
    bool mValue;
};

/**
 * The Number class represents a 64-bit double-precision floating point. This class wraps the standard double type.
 */
class Number final
{
public:
    /**
     * Creates a Number object with a value of zero.
     */
    Number();

    /**
     * Creates a Number object from a standard C double type.
     */
    Number(double value);

    /**
     * Creates a copy of a Number object using value semantics.
     */
    Number(const Number &number);

    /**
     * Creates a copy of a Number object using move semantics.
     */
    Number(Number &&number);

    /**
     * Destroys the Number object.
     */
    ~Number();

    /**
     * Gets the value of the Number object.
     * @return Returns the wrapped double value.
     */
    double valueOf() const { return mValue; }

    /**
     * Converts the Number object to a 64-bit double.
     */
    operator double() const { return mValue; }

    /**
     * Converts the Number object to a 32-bit float.
     */
    operator float() const { return (float)mValue; }

    /**
     * Converts the Number object to an unsigned 8-bit integer.
     */
    operator uint8_t() const { return (uint8_t)mValue; }

    /**
     * Converts the Number object to an unsigned 16-bit integer.
     */
    operator uint16_t() const { return (uint16_t)mValue; }

    /**
     * Converts the Number object to an unsigned 32-bit integer.
     */
    operator uint32_t() const { return (uint32_t)mValue; }

    /**
     * Converts the Number object to an unsigned 64-bit integer.
     */
    operator uint64_t() const { return (uint64_t)mValue; }

    /**
     * Converts the Number object to an signed 8-bit integer.
     */
    operator int8_t() const { return (int8_t)mValue; }

    /**
     * Converts the Number object to an signed 16-bit integer.
     */
    operator int16_t() const { return (int16_t)mValue; }

    /**
     * Converts the Number object to an signed 32-bit integer.
     */
    operator int32_t() const { return (int32_t)mValue; }

    /**
     * Converts the Number object to an signed 64-bit integer.
     */
    operator int64_t() const { return (int64_t)mValue; }

    /**
     * Sets the Number object equal to another using value semantics.
     * @param rhs The Number object on the right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    Number &operator=(const Number &rhs);

    /**
     * Sets the Number object equal to another using move semantics.
     * @param rhs The Number object on the right-hand side of the assignment expression.
     * @return Returns a reference to itself.
     */
    Number &operator=(Number &&rhs);

private:
    /**
     * The value of the number.
     */
    double mValue;
};

/**
 * The Color class represetns any 64-bit color.
 */
class Color final
{
public:
    /**
     * Creates a Color object. This is a default constructor that creates a color representing the color black (#000).
     */
    Color();

    /**
     * Creates a Color object from a Number.
     */
    Color(Number value);

    /**
     * Creates a Color object from red, green, and blue channels. An optional alpha channel may be supplied. The default value of the alpha channel is 1.0 (fully opaque).
     */
    Color(Number r, Number g, Number b, Number a = 1.0);

    /**
     * Creates a copy of a Color object using value semantics.
     * @color The color in which to copy.
     */
    Color(const Color &color);

    /**
     * Creates a copy of a Color object using move semantics.
     * @color The color in which to copy.
     */
    Color(Color &&color);

    /**
     * Destroys the Color object.
     */
    ~Color();

    /**
     *
     */
    Number getRed() const;

    /**
     *
     */
    Number getGreen() const;

    /**
     *
     */
    Number getBlue() const;

    /**
     * Gets the value of the alpha channel.
     * @return Returns a number that represents the color's alpha.
     */
    Number getAlpha() const;

    /**
     * Gets the value of the Color object.
     * @return Returns the numerical value of the color.
     */
    Number valueOf() const;

    /**
     * Sets the Color object equal to another using value semantics.
     * @return Returns a reference to itself.
     */
    Color &operator=(const Color &color);

    /**
     * Sets the Color object equal to another using move semantics.
     * @return Returns a reference to itself.
     */
    Color &operator=(Color &&color);

private:
    /**
     * The numerical value of the color.
     */
    Number mValue;
};

/**
 *
 */
class String final
{
public:
    /**
     *
     */
    String();

    /**
     *
     */
    String(const char *);

    /**
     *
     */
    String(const String &string);

    /**
     *
     */
    String(String &&string);

    /**
     *
     */
    ~String();

    /**
     *
     */
    Boolean toBoolean() const;

    /**
     *
     */
    String toString() const;

    /**
     *
     */
    Number toNumber() const;

    /**
     *
     */
    Color toColor() const;

    /**
     *
     */
    Number getLength() const { return mLength; }

    /**
     *
     */
    operator bool() const { return mLength.valueOf() != 0.0; }

    /**
     *
     */
    String &operator=(const String &rhs);

    /**
     *
     */
    String &operator=(String &&rhs);

private:
    Number mLength;
};

/**
 *
 */
class Any final
{
public:
    /**
     *
     */
    Any();

    /**
     *
     */
    Any(undefined_t);

    /**
     *
     */
    Any(std::nullptr_t);

    /**
     *
     */
    Any(Boolean _bool);

    /**
     *
     */
    Any(Color color);

    /**
     *
     */
    Any(String string);

    /**
     *
     */
    Any(Number number);

    /**
     *
     */
    Any(object_ptr<HElement> object);

    /**
     *
     */
    Any(const Any &any);

    /**
     *
     */
    Any(Any &&any);

    /**
     *
     */
    ~Any();

    const std::type_info &type() const { return mContent->type(); }

    template <typename T>
    bool isA() const
    {
        return type() == typeid(T);
    }

    /**
     *
     */
    bool isNull() const;

    /**
     *
     */
    bool isUndefined() const;

    /**
     *
     */
    bool isBoolean() const;

    /**
     *
     */
    bool isColor() const;

    /**
     *
     */
    bool isNumber() const;

    /**
     *
     */
    bool isString() const;

    operator bool() const;

    Any &operator=(const Any &rhs);

    Any &operator=(Any &&rhs);

    template <typename T>
    operator T() const
    {
        if (mContent->type() != typeid(T))
            throw bad_any_cast{};

        return static_cast<holder<T> *>(mContent.get())->value;
    }

private:
    /**
     *
     */
    struct placeholder
    {
        /**
         *
         */
        virtual const std::type_info &type() const = 0;

        /**
         *
         */
        virtual placeholder *clone() const = 0;
    };

    template <typename T>
    struct holder : public placeholder
    {
        /**
         *
         */
        T value;

        holder(T val)
            : value{ val }
        {
        }

        virtual ~holder() {}

        /**
         *
         */
        virtual const std::type_info &type() const override { return typeid(T); }

        /**
         *
         */
        virtual placeholder *clone() const override { return new holder<T>{ value }; }
    };

    std::unique_ptr<placeholder> mContent;
};

/**
 * The boolean value true.
 */
const Boolean True{ true };

/**
 * The boolean value false.
 */
const Boolean False{ false };

} // namespace hydro::engine

#endif /* __h3o_engine_core__ */
