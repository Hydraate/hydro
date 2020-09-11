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

#ifndef __h3o_Assignment__
#define __h3o_Assignment__

#include "BinaryExpression.hpp"

namespace hydro::compiler
{
class Assignment final : public BinaryExpression
{
public:
    Assignment(AST *owner);
    virtual ~Assignment();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_Assignment__ */
