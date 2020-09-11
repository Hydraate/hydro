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

#ifndef __h3o_CharacterLiteral__
#define __h3o_CharacterLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class CharacterLiteral final : public Expression
{
public:
    char value;

    CharacterLiteral(AST *owner);
    virtual ~CharacterLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_CharacterLiteral__ */
