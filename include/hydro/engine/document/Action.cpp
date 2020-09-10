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

#include "Action.hpp"

namespace hydro::engine
{
Action::Action(Entity *parent, ActionIdentity *identity)
    : Entity{ parent, identity }
{
}

Action::~Action()
{
}

} // namespace hydro::engine
