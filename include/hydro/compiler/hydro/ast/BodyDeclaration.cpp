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

#include "BodyDeclaration.hpp"

namespace hydro::compiler
{
BodyDeclaration::BodyDeclaration(AST *owner) : Statement{owner}
{
    body = nullptr;
}

BodyDeclaration::~BodyDeclaration()
{
    delete body;
}

} // namespace hydro::compiler
