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

#include "MultiplicityLiteral.hpp"

namespace hydro::engine
{
MultiplicityLiteral::MultiplicityLiteral(NumberLiteral *min, NumberLiteral *max) : Expression{}
{
    mMin = min;
    mMax = max;
}

MultiplicityLiteral::~MultiplicityLiteral()
{
}

} // namespace hydro::engine
