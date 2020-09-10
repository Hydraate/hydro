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

#include "Prototype.hpp"

namespace hydro::engine
{

Prototype::Prototype(Entity *parent, PrototypeIdentity *identity) : Entity{ parent, identity }
{
}

Prototype::~Prototype()
{
}

} // namespace hydro::engine
