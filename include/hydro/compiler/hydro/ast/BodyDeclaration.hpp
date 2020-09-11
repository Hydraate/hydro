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

#ifndef __h3o_BodyDeclaration__
#define __h3o_BodyDeclaration__

#include "Block.hpp"
#include "Declaration.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class BodyDeclaration : public Statement, public Declaration
{
protected:
    BodyDeclaration(AST *owner);

public:
    Block *body;

    virtual ~BodyDeclaration();
};

} // namespace hydro::compiler

#endif /* __h3o_BodyDeclaration__ */
