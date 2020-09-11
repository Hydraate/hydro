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

#ifndef __h3o_MethodDeclaration__
#define __h3o_MethodDeclaration__

#include "Declaration.hpp"
#include "FunctionArgumentsList.hpp"
#include "SimpleName.hpp"
#include "Statement.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class MethodDeclaration final : public Statement, public Declaration
{
public:
    SimpleName *name;
    FunctionArgumentsList *arguments;
    TypeSpecifier *returnType;

    MethodDeclaration(AST *owner);
    virtual ~MethodDeclaration();
    void accept(ASTVisitor *visitor);
};

} // namespace hydro::compiler

#endif /* __h3o_MethodDeclaration__ */
