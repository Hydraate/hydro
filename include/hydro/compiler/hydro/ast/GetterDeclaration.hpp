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

#ifndef __h3o_GetterDeclaration__
#define __h3o_GetterDeclaration__

#include "BodyDeclaration.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class GetterDeclaration : public BodyDeclaration
{
public:
    SimpleName *valueName;

    GetterDeclaration(AST *owner);
    virtual ~GetterDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* GetterDeclaration_hpp */
