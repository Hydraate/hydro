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

#include "WhileBinding.hpp"

namespace hydro::engine
{

WhileBinding::WhileBinding(compiler::Token token, Expression *condition) : Binding{ token }
{
    mCondition = condition;
}

WhileBinding::~WhileBinding()
{
    delete mCondition;
}

} // namespace hydro::engine
