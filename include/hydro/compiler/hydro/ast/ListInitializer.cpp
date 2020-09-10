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

#include "ListInitializer.hpp"

namespace hydro::compiler
{
ListInitializer::ListInitializer(AST *owner) : Expression{owner} {}

ListInitializer::~ListInitializer()
{
}

void ListInitializer::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void ListInitializer::append(Expression *item)
{
    m_items.push_back(item);
}

} // namespace hydro::compiler
