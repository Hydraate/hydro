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

#ifndef __h3o_internal_QualifiedName__
#define __h3o_internal_QualifiedName__

#include "SimpleName.hpp"

namespace hydro::compiler
{
class QualifiedName final : public Name
{
public:
    QualifiedName(AST *owner);
    virtual ~QualifiedName();
    virtual void accept(ASTVisitor *visitor) override;
    SimpleName *getName() const { return m_name; }
    void setName(SimpleName *name) { m_name = name; }
    Name *getQualifier() const { return m_qualifier; }
    void setQualifier(Name *qualifier) { m_qualifier = qualifier; }
    virtual std::string getValue() const override;
    virtual bool isSimpleName() const override { return false; }
    virtual bool isQualifiedName() const override { return true; }
    virtual bool compare(Name *name) const override;

private:
    SimpleName *m_name;
    Name *m_qualifier;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_QualifiedName__ */
