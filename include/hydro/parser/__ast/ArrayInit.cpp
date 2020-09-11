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

#include "ArrayInit.hpp"

namespace hydro
{

ArrayInit::ArrayInit(lex_token token) : Literal{token} {}

ArrayInit::~ArrayInit() {}

void ArrayInit::append(ast_expr elementExpr)
{
	addChild(elementExpr);
}

} // namespace hydro
