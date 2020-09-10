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

#include "Invocation.hpp"

namespace hydro::engine
{
Invocation::Invocation(Entity *parent, InvocationIdentity *identity) : Entity{parent, identity}
{
}

Invocation::~Invocation()
{
}

} // namespace hydro::engine
