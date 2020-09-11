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

#ifndef __h3omPostfixExpression__
#define __h3omPostfixExpression__

#include "UnaryExpression.hpp"

namespace hydro::compiler
{
class PostfixExpression : public UnaryExpression
{
public:
    PostfixExpression(AST *owner);
    virtual ~PostfixExpression();
};

} // namespace hydro::compiler

#endif /* __h3omPostfixExpression__ */
