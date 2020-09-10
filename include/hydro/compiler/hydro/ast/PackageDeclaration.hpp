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

#ifndef __h3o_PackageDeclaration__
#define __h3o_PackageDeclaration__

#include "Declaration.hpp"
#include "Name.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class PackageDeclaration final : public Statement, public Declaration
{
public:
    Name *name;
    PackageDeclaration(AST *owner);
    virtual ~PackageDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_PackageDeclaration__ */
