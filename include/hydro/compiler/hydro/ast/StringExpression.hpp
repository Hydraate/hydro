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

#ifndef __h3o_StringExpression__
#define __h3o_StringExpression__

#include "Expression.hpp"

namespace hydro::compiler
{
class StringExpression : public Expression
{
public:
    std::string value;
    StringExpression(AST *owner);
    virtual ~StringExpression();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_StringExpression__ */
