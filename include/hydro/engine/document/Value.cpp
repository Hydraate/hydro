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

#include "Value.hpp"

namespace hydro::engine
{
/**
 * Implements the constructor of the Value.
 */
Value::Value()
{
}

/**
 * Implements the constructor of the Value class with initialization from a token.
 */
Value::Value(compiler::Token token) : Node{token}
{
}

/**
 * Implements the destructor of the Value class.
 */
Value::~Value()
{
}

} // namespace hydro::engine
