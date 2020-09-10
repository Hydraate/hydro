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

#ifndef __h3o_OperatorDeclaration__
#define __h3o_OperatorDeclaration__

#include "BodyDeclaration.hpp"

namespace hydro::compiler
{
class OperatorDeclaration final : public BodyDeclaration
{
public:
    SimpleName *_operator;

    OperatorDeclaration(AST *owner);
    virtual ~OperatorDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_OperatorDeclaration__ */
