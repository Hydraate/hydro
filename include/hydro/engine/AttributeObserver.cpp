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

#include "AttributeObserver.hpp"

namespace hydro::engine
{
/**
 * 
 */
AttributeObserver::AttributeObserver(const AttributeBinding *attrBinding, Space *space)
{
    mAttrBinding = attrBinding;
    mSpace = space;
}

/**
 * 
 */
AttributeObserver::~AttributeObserver()
{
}

} // namespace hydro::engine
