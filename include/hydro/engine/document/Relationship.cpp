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

#include "Relationship.hpp"

namespace hydro::engine
{

Relationship::Relationship(Name *name) : Node{}
{
    mName = name;
    mMultiplicity = nullptr;
}

Relationship::~Relationship()
{
    delete mName;
    delete mMultiplicity;
}

} // namespace hydro::engine
