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

#ifndef __h3o_ImportDeclaration__
#define __h3o_ImportDeclaration__

#include "Name.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class ImportDeclaration : public Statement
{
public:
    Name *target;

    ImportDeclaration(AST *owner);
    virtual ~ImportDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ImportDeclaration__ */
