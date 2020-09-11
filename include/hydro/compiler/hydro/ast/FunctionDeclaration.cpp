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

#include "FunctionDeclaration.hpp"

namespace hydro::compiler
{
FunctionDeclaration::FunctionDeclaration(AST *owner) : BodyDeclaration{owner}
{
    arguments = nullptr;
}

FunctionDeclaration::~FunctionDeclaration() {}

} // namespace hydro::compiler
