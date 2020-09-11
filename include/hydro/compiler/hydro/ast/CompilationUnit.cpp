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

#include "CompilationUnit.hpp"

namespace hydro::compiler
{
CompilationUnit::CompilationUnit(AST *owner) : ASTNode{owner} {}

CompilationUnit::~CompilationUnit()
{
}

void CompilationUnit::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void CompilationUnit::append(Statement *statement)
{
    m_statements.push_back(statement);
}

void CompilationUnit::append(ImportDeclaration *imprt)
{
    m_imports.push_back(imprt);
}

} // namespace hydro::compiler
