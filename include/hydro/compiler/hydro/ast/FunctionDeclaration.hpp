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

#ifndef __h3o_FunctionDeclaration__
#define __h3o_FunctionDeclaration__

#include "BodyDeclaration.hpp"
#include "FunctionArgumentsList.hpp"

namespace hydro::compiler
{
class FunctionDeclaration : public BodyDeclaration
{
public:
    FunctionArgumentsList *arguments;
    FunctionDeclaration(AST *owner);
    virtual ~FunctionDeclaration();
};

} // namespace hydro::compiler

#endif /* __h3o_FunctionDeclaration__ */
