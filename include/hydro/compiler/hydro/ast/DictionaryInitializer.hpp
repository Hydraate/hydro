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

#ifndef __h3o_DictionaryInitializer__
#define __h3o_DictionaryInitializer__

#include "DictionaryEntry.hpp"

namespace hydro::compiler
{
class DictionaryInitializer final : public Expression
{
public:
    DictionaryInitializer(AST *owner);
    virtual ~DictionaryInitializer();
    virtual void accept(ASTVisitor *visitor) override;
    void append(DictionaryEntry *entry);
    const std::list<DictionaryEntry *> &entries() const { return m_entries; }

private:
    std::list<DictionaryEntry *> m_entries;
};

} // namespace hydro::compiler

#endif /* __h3o_DictionaryInitializer__ */
