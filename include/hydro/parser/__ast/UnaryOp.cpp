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

#include "UnaryOp.hpp"

namespace hydro
{

UnaryOp::UnaryOp(lex_token token, ast_expr expr, bool postfix) : Expr{token}, _expr{expr}, mPostfix{postfix}
{
	addChild(_expr);
}

UnaryOp::UnaryOp(ast_expr expr, lex_token token) : Expr{token}, _expr{expr}, mPostfix{true}
{
	addChild(_expr);
}

UnaryOp::~UnaryOp() {}

} // namespace hydro
