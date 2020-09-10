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

#include "Procedure.hpp"

namespace hydro::engine
{

Procedure::Procedure(Entity *parent, ProcedureIdentity *identity)
    : Entity{parent, identity}
{
}

Procedure::~Procedure()
{
}

} // namespace hydro::engine
