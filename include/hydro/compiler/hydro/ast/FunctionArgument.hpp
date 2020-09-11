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

#ifndef __h3o_FunctionArgument__
#define __h3o_FunctionArgument__

#include "ASTNode.hpp"
#include "Expression.hpp"
#include "SimpleName.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class FunctionArgument : public ASTNode
{
public:
    SimpleName *name;
    TypeSpecifier *type;
    Expression *defaultValue;

    FunctionArgument(AST *owner);
    virtual ~FunctionArgument();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_FunctionArgument__ */
