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

#include "InterfaceDeclaration.hpp"

namespace hydro::compiler
{
InterfaceDeclaration::InterfaceDeclaration(AST *owner) : BodyDeclaration{owner}
{
    name = nullptr;
}

InterfaceDeclaration::~InterfaceDeclaration()
{
}

} // namespace hydro::compiler
