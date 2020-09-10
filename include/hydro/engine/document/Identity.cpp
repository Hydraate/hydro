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

#include "Identity.hpp"

namespace hydro::engine
{
Identity::Identity()
{
    mRelationships = nullptr;
    mSubject = nullptr;
    mID = nullptr;
}

Identity::Identity(Subject *subject)
{
    mRelationships = nullptr;
    mSubject = subject;
    mID = nullptr;
}

Identity::Identity(IdentityRelationshipsList *relationships, Subject *subject)
{
    mRelationships = relationships;
    mSubject = subject;
    mID = nullptr;
}

Identity::Identity(IdentityRelationshipsList *relationships, Subject *subject, ElementID *id)
{
    mRelationships = relationships;
    mSubject = subject;
    mID = id;
}

Identity::~Identity()
{
}

} // namespace hydro::engine
