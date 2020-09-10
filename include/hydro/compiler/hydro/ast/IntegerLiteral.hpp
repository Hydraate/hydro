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

#ifndef __h3o_IntegerLiteral__
#define __h3o_IntegerLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class IntegerLiteral : public Expression
{
public:
    int32_t value;

    IntegerLiteral(AST *owner);
    virtual ~IntegerLiteral();
};

} // namespace hydro::compiler

#endif /* __h3o_IntegerLiteral__ */
