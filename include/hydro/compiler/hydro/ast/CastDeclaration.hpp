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

#ifndef __h3o_CastDeclaration__
#define __h3o_CastDeclaration__

#include "BodyDeclaration.hpp"
#include "Name.hpp"

namespace hydro::compiler
{
class CastDeclaration final : public BodyDeclaration
{
public:
    Name *target;

    CastDeclaration(AST *owner);
    virtual ~CastDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_CastDeclaration__ */
