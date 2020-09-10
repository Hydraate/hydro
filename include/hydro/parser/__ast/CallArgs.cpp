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

#include "CallArgs.hpp"

namespace hydro
{

CallArgs::CallArgs() : Expr{} {}

CallArgs::~CallArgs() {}

void CallArgs::append(ast_expr argExpr) { addChild(argExpr); }

} // namespace hydro
