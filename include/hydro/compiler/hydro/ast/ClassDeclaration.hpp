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

#ifndef __h3o_ClassDeclaration__
#define __h3o_ClassDeclaration__

#include <list>

#include "BodyDeclaration.hpp"
#include "SimpleName.hpp"

namespace hydro::compiler
{
class ClassDeclaration final : public BodyDeclaration
{
public:
    SimpleName *name;

    ClassDeclaration(AST *owner);
    virtual ~ClassDeclaration();
    virtual void accept(ASTVisitor *visitor) override;
    void appendParent(Name *parent);
    const std::list<Name *> &parents() const { return m_parents; }

private:
    std::list<Name *> m_parents;
};

} // namespace hydro::compiler

#endif /* __h3o_ClassDeclaration__ */
