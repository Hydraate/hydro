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

#include "Block.hpp"

namespace hydro::compiler
{
Block::Block(AST *owner) : Statement{owner} {}

Block::~Block()
{
    for (Statement *statement : m_statements)
        delete statement;
}

void Block::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void Block::append(Statement *statement)
{
    m_statements.push_back(statement);
}

} // namespace hydro::compiler
