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

#ifndef __h3o_DictionaryEntry__
#define __h3o_DictionaryEntry__

#include <list>

#include "Expression.hpp"

namespace hydro::compiler
{
class DictionaryEntry final : public ASTNode
{
public:
    Expression *key;
    Expression *value;

    DictionaryEntry(AST *owner);
    virtual ~DictionaryEntry();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_DictionaryEntry__ */
