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

#ifndef __h3o_engine_Space__
#define __h3o_engine_Space__

#include <string>

#include "Attribute.hpp"
#include "Value.hpp"
#include "core.hpp"

namespace hydro::engine
{
/**
 * The Space class stores information in memory like a variable.
 */
struct Space
{
    /**
     * The space's name.
     */
    std::string name;

    /**
     * The space's value. The default is undefined.
     */
    Any value;
};

} // namespace hydro::engine

#endif /* __h3o_engine_AttributeSpace__ */
