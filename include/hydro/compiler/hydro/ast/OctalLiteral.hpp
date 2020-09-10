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

#ifndef __h3o_OctalLiteral__
#define __h3o_OctalLiteral__

#include "Expression.hpp"

namespace hydro::compiler
{
class OctalLiteral : public Expression
{
public:
    OctalLiteral(AST *owner);
    virtual ~OctalLiteral();
};

} // namespace hydro::compiler

#endif /* __h3o_OctalLiteral__ */
