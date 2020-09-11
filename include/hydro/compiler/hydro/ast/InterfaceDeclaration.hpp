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

#ifndef __h3o_InterfaceDeclaration__
#define __h3o_InterfaceDeclaration__

#include "BodyDeclaration.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class InterfaceDeclaration : public BodyDeclaration
{
public:
    SimpleName *name;

    InterfaceDeclaration(AST *owner);
    virtual ~InterfaceDeclaration();
};

} // namespace hydro::compiler

#endif /* InterfaceDeclaration_hpp */
