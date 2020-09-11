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

#include "WhenBinding.hpp"

namespace hydro::engine
{

WhenBinding::WhenBinding(compiler::Token token, Expression *condition) : Binding{ token }
{
    mCondition = condition;
}

WhenBinding::~WhenBinding()
{
    delete mCondition;
}

} // namespace hydro::engine
