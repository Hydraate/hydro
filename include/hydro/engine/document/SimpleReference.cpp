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

#include "SimpleReference.hpp"

namespace hydro::engine
{

SimpleReference::SimpleReference(Subject *subject) : Reference{}
{
    mSubject = subject;
}

SimpleReference::~SimpleReference()
{
}

} // namespace hydro::engine
