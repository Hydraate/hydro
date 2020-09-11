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

#ifndef __h3o_Expression__
#define __h3o_Expression__

#include "ASTNode.hpp"

namespace hydro::compiler
{
class Expression : public ASTNode
{
protected:
    Expression(AST *owner);

public:
    virtual ~Expression();
};

} // namespace hydro::compiler

#endif /* __h3o_Expression__ */
