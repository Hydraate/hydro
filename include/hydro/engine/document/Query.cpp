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

#include "Query.hpp"

namespace hydro::engine
{

Query::Query(Entity *parent, QueryIdentity *identity) : Entity{ parent, identity }
{
}

Query::~Query()
{
}

} // namespace hydro::engine
