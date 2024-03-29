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

#include "ThrowStmt.hpp"

namespace hydro
{

ThrowStmt::ThrowStmt(lex_token token, ast_expr expr) : Stmt{token}, _expr{expr}
{
	addChild(expr);
}

ThrowStmt::~ThrowStmt() {}

} // namespace hydro
