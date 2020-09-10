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

#ifndef __h3o_UnaryOp__
#define __h3o_UnaryOp__

#include "Expr.hpp"

namespace hydro
{

class UnaryOp : public Expr
{
private:
	ast_expr _expr;
	bool mPostfix;

public:
	UnaryOp(lex_token token, ast_expr expr, bool postfix = false);
	UnaryOp(ast_expr expr, lex_token token);
	virtual ~UnaryOp();
	ast_expr expr() const { return _expr; }
	bool isPostfix() const { return mPostfix; }
};

typedef UnaryOp *ast_unary;

} // namespace hydro

#endif /* __h3o_UnaryOp__ */
