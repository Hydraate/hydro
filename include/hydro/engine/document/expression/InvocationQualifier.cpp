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

#include "InvocationSelector.hpp"

namespace hydro::engine
{
InvocationSelector::InvocationSelector(Target *target)
{
    mTarget = target;
}

InvocationSelector::~InvocationSelector()
{
    delete mTarget;
}

} // namespace hydro::engine
