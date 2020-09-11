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

#include "QueryIdentity.hpp"

namespace hydro::engine
{
QueryIdentity::QueryIdentity(QueryTarget *target) : Identity{target}
{
    mTarget = target;
}

QueryIdentity::~QueryIdentity()
{
    delete mTarget;
}

} // namespace hydro::engine
