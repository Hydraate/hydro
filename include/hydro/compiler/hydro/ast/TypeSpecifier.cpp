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

#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
TypeSpecifier::TypeSpecifier(AST *owner) : ASTNode{owner} {}

TypeSpecifier::~TypeSpecifier() {}

} // namespace hydro::compiler
