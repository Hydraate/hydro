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

#include "JsonInitializer.hpp"

namespace hydro::compiler
{
JsonInitializer::JsonInitializer(AST *owner) : Expression{owner} {}

JsonInitializer::~JsonInitializer() {}

void JsonInitializer::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
