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

#include "SimpleName.hpp"

namespace hydro::engine
{
SimpleName::SimpleName(compiler::Token token) : Name{ token }
{
    mValue = token.value();
}

SimpleName::~SimpleName()
{
}

} // namespace hydro::engine
