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

#include "StringLiteral.hpp"

namespace hydro::compiler
{
StringLiteral::StringLiteral(AST *owner) : Expression{owner} {}

StringLiteral::~StringLiteral()
{
    for (Expression *value : m_values)
        delete value;
}

void StringLiteral::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void StringLiteral::append(Expression *value)
{
    m_values.push_back(value);
}

} // namespace hydro::compiler
