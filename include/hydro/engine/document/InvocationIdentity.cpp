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

#include "InvocationIdentity.hpp"

namespace hydro::engine
{
InvocationIdentity::InvocationIdentity(InvocationTarget *target) : Identity{ target }
{
    mTarget = target;
}

InvocationIdentity::~InvocationIdentity()
{
}

} // namespace hydro::engine
