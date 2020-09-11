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

#ifndef __h3o_Identifier__
#define __h3o_Identifier__

#include "Expression.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class Identifier : public Expression
{
public:
    SimpleName *value;

    Identifier(AST *owner);
    virtual ~Identifier();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_Identifier__ */
