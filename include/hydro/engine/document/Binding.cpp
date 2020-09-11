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

#include "Binding.hpp"

namespace hydro::engine
{

Binding::Binding() : Node{}
{
}

Binding::Binding(compiler::Token token) : Node{ token }
{
}

Binding::~Binding()
{
}

} // namespace hydro::engine
