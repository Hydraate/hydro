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

#ifndef __h3o_SubscriptExpression__
#define __h3o_SubscriptExpression__

#include "BinaryExpression.hpp"

namespace hydro::compiler
{
class SubscriptExpression : public BinaryExpression
{
public:
    SubscriptExpression(AST *owner);
    virtual ~SubscriptExpression();
};

} // namespace hydro::compiler

#endif /* __h3o_SubscriptExpression__ */
