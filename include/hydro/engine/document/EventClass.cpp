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

#include "EventClass.hpp"

namespace hydro::engine
{
EventClass::EventClass(Name *name)
    : EntityType{name}
{
    mSymbol = nullptr;
}

EventClass::~EventClass()
{
}

} // namespace hydro::engine
