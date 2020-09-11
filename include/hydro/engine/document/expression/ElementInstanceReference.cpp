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

#include "ElementInstanceQualifier.hpp"

namespace hydro::engine
{
ElementInstanceQualifier::ElementInstanceQualifier(ID id)
{
    mClass = nullptr; // does not contain a class qualifier
}

ElementInstanceQualifier::ElementInstanceQualifier(Name *elementClass, ID id)
{
    mClass = elementClass;
    mID = id;
}

} // namespace hydro::engine
