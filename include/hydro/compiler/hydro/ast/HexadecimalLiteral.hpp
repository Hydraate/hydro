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

#ifndef __h3o_HexadecimalLiteral__
#define __h3o_HexadecimalLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class HexadecimalLiteral : public Expression
{
public:
    int32_t value;

    HexadecimalLiteral(AST *owner);
    virtual ~HexadecimalLiteral();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_HexadecimalLiteral__ */
