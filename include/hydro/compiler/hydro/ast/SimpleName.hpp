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

#ifndef __h3o_internal_SimpleName__
#define __h3o_internal_SimpleName__

#include <string>

#include "Name.hpp"

namespace hydro::compiler
{
class SimpleName final : public Name
{
public:
    SimpleName(AST *node);
    virtual ~SimpleName();
    virtual void accept(ASTVisitor *visitor) override;
    virtual std::string getValue() const override { return m_value; }
    void setValue(std::string value) { m_value = value; }
    virtual bool isSimpleName() const override { return true; }
    virtual bool isQualifiedName() const override { return false; }
    virtual bool compare(Name *name) const override;

private:
    std::string m_value;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_SimpleName__ */
