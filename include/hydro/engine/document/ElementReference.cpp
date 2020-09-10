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

#include "ElementReference.hpp"

namespace hydro::engine
{
ElementReference::ElementReference(ElementClass *elementClass, ElementID *id) : SimpleReference{ elementClass }
{
    mID = id;
}

ElementReference::~ElementReference()
{
}

} // namespace hydro::engine
