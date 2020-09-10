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

#include "PrototypeIdentity.hpp"

namespace hydro::engine
{

PrototypeIdentity::PrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *elementClass) : Identity{ relationships, elementClass }
{
    mParentClass = nullptr;
}

PrototypeIdentity::PrototypeIdentity(IdentityRelationshipsList *relationships, ElementClass *parentClass, ElementClass *derivedClass) : Identity{ relationships, derivedClass }
{
    mParentClass = parentClass;
}

PrototypeIdentity::~PrototypeIdentity()
{
    delete mParentClass;
}

} // namespace hydro::engine
