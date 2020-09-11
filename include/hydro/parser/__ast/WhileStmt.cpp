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

#include "WhileStmt.hpp"

namespace hydro
{

WhileStmt::WhileStmt(lex_token token, Expr *cond, Stmt *body) : Stmt{token}, _cond{cond}, _body{body}
{
	addChild(cond);
	addChild(body);
}

WhileStmt::~WhileStmt() {}

} // namespace hydro
