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

#include "InvocationTarget.hpp"

namespace hydro::engine
{

InvocationTarget::InvocationTarget(Reference *reference) : Target{}
{
    mReference = reference;
}

InvocationTarget::~InvocationTarget()
{
}

} // namespace hydro::engine
