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

#include "Attribute.hpp"

namespace hydro::engine
{
/**
 * 
 */
Attribute::Attribute(Name *name, Value *value)
{
    mName = name;
    mValue = value;
}

/**
 * Destroys the Attribute object and frees resources.
 */
Attribute::~Attribute()
{
}

} // namespace hydro::engine
