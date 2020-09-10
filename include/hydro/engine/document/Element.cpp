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

#include "Element.hpp"

namespace hydro::engine
{

Element::Element(Entity *parent, ElementIdentity *identity)
    : Entity{parent, identity}
{
}

Element::~Element()
{
}

} // namespace hydro::engine
