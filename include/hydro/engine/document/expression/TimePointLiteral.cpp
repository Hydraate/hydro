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

#include "TimePointLiteral.hpp"

namespace hydro::engine
{
TimePointLiteral::TimePointLiteral(NumberLiteral *minutes, NumberLiteral *seconds, NumberLiteral *milliseconds)
{
    mHours = nullptr;
    mMinutes = minutes;
    mSeconds = seconds;
    mMilliseconds = milliseconds;
}

TimePointLiteral::TimePointLiteral(NumberLiteral *hours, NumberLiteral *minutes, NumberLiteral *seconds, NumberLiteral *milliseconds)
{
    mHours = hours;
    mMinutes = minutes;
    mSeconds = seconds;
    mMilliseconds = milliseconds;
}

TimePointLiteral::~TimePointLiteral()
{
}

} // namespace hydro::engine
