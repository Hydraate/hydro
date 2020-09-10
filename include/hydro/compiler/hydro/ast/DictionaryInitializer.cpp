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

#include "DictionaryInitializer.hpp"

namespace hydro::compiler
{
DictionaryInitializer::DictionaryInitializer(AST *owner) : Expression{owner} {}

DictionaryInitializer::~DictionaryInitializer()
{
}

void DictionaryInitializer::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

void DictionaryInitializer::append(DictionaryEntry *entry)
{
    m_entries.push_back(entry);
}

} // namespace hydro::compiler
