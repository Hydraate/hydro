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

#include "InvocationReference.hpp"

namespace hydro::engine
{

InvocationReference::InvocationReference(InvocationTarget *target) : SimpleReference{ target }
{
    mTarget = target;
}

InvocationReference::~InvocationReference()
{
}

} // namespace hydro::engine
