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

#include "DictionaryEntry.hpp"

namespace hydro::compiler
{
DictionaryEntry::DictionaryEntry(AST *owner) : ASTNode{owner}
{
    key = value = nullptr;
}

DictionaryEntry::~DictionaryEntry()
{
}

void DictionaryEntry::accept(ASTVisitor *visitor)
{
    visitor->visit(this);
}

} // namespace hydro::compiler
