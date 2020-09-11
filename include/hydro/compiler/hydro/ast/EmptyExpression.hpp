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

#ifndef __h3o_EmptyExpression__
#define __h3o_EmptyExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class EmptyExpression : public Expression
{
public:
    EmptyExpression(AST *owner);
    virtual ~EmptyExpression();
    virtual void accept(ASTVisitor *visitor);
};

} // namespace hydro::compiler

#endif /* __h3o_EmptyExpression__ */
