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

#ifndef __h3o_engine_TimePointLiteral__
#define __h3o_engine_TimePointLiteral__

#include "NumberLiteral.hpp"

namespace hydro::engine
{
/**
 *
 */
class TimePointLiteral : public Expression
{
public:
    /**
     * Creates a TimePointLiteral object that represents minutes and seconds only. This is normally a time point less than an hour.
     */
    TimePointLiteral(NumberLiteral *minutes, NumberLiteral *seconds, NumberLiteral *milliseconds);

    /**
     * Creates a TimePointLiteral object that represents hours, minutes, and seconds.
     */
    TimePointLiteral(NumberLiteral *hours, NumberLiteral *minutes, NumberLiteral *seconds, NumberLiteral *milliseconds);

    /**
     * Destroys the TimePointLiteral object.
     */
    virtual ~TimePointLiteral();
    
    /**
     * Accepts a visitor allowing the visitor to visit the time point literal expression.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }

    /**
     *
     * @return ...
     */
    NumberLiteral *getHours() const { return mHours; }
    
    /**
     *
     * @return ...
     */
    NumberLiteral *getMinutes() const { return mMinutes; }
    
    /**
     *
     * @return ...
     */
    NumberLiteral *getSeconds() const { return mSeconds; }

    /**
     *
     * @return ...
     */
    NumberLiteral *getMilliseconds() const { return mMilliseconds; }

private:
    /**
     *
     */
    NumberLiteral *mHours;

    /**
     *
     */
    NumberLiteral *mMinutes;

    /**
     *
     */
    NumberLiteral *mSeconds;
    
    /**
     *
     */
    NumberLiteral *mMilliseconds;
};

} // namespace hydro::engine

#endif /* __h3o_engine_TimePointLiteral__ */
