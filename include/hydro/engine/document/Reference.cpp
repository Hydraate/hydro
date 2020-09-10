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

#include "Reference.hpp"

namespace hydro::engine
{

Reference::Reference()
{
}

Reference::Reference(compiler::Token token) : Node{ token }
{
}

Reference::~Reference()
{
}

} // namespace hydro::engine
