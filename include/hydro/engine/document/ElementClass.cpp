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

#include "ElementClass.hpp"

namespace hydro::engine
{
ElementClass::ElementClass(Name *name)
    : EntityType{name}
{
}

ElementClass::~ElementClass()
{
}

} // namespace hydro::engine
