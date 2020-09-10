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

#include "CompoundReference.hpp"

namespace hydro::engine
{
CompoundReference::CompoundReference(Reference *subject, compiler::Token token, SimpleReference *target) : Reference{ token }
{
    mSubject = subject;
    mTarget = target;
}

CompoundReference::~CompoundReference()
{
}

} // namespace hydro::engine
