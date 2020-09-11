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

#ifndef __h3o_engine_Attribute__
#define __h3o_engine_Attribute__

#include <string>

#include "Attribute.hpp"
#include "Value.hpp"

namespace hydro::engine
{
/**
 * The AttributeValue class stores information about the a for entities.
 */
struct AttributeSpace
{
    /**
     * The attribute's name.
     */
    Attribute *attr;

    /**
     * The attribute's value.
     */
    hvalue value;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Attribute__ */
