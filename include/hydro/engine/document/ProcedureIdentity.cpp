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

#include "ProcedureIdentity.hpp"

namespace hydro::engine
{
ProcedureIdentity::ProcedureIdentity(IdentityRelationshipsList *relationships, ProcedureClass *type)
    : Identity{relationships, type}
{
}

ProcedureIdentity::~ProcedureIdentity()
{
}

} // namespace hydro::engine
