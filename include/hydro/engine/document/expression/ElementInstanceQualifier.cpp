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

#include "ElementSelector.hpp"

namespace hydro::engine
{
/**
 *
 */
ElementSelector::ElementSelector(ID id) : Expression{}
{
    mClass = nullptr; // does not contain a class qualifier
}

/**
 *
 */
ElementSelector::ElementSelector(Name *elementClass, ID id) : Expression{}
{
    mClass = elementClass;
    mID = id;
}

/**
 *
 */
ElementSelector::~ElementSelector()
{
    delete mClass;
}

} // namespace hydro::engine
