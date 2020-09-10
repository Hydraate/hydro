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

#include "ActionReference.hpp"

namespace hydro::engine
{

ActionReference::ActionReference(EventClass *eventClass) : SimpleReference{ eventClass }
{
}

ActionReference::~ActionReference()
{
}

} // namespace hydro::engine
