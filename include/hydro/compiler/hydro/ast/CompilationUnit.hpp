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

#ifndef __h3o_CompilationUnit__
#define __h3o_CompilationUnit__

#include <list>

#include "ASTNode.hpp"
#include "ImportDeclaration.hpp"
#include "Statement.hpp"

namespace hydro::compiler
{
class CompilationUnit final : public ASTNode
{
public:
    CompilationUnit(AST *owner);
    virtual ~CompilationUnit();
    virtual void accept(ASTVisitor *visitor) override;
    void append(Statement *statement);
    void append(ImportDeclaration *imprt);
    const std::list<Statement *> &statements() const { return m_statements; }
    const std::list<ImportDeclaration *> &imports() const { return m_imports; }

private:
    std::list<Statement *> m_statements;
    std::list<ImportDeclaration *> m_imports;
};

} // namespace hydro::compiler

#endif /* __h3o_CompilationUnit__ */
