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

#ifndef __h3o_Statement__
#define __h3o_Statement__

#include "ASTNode.hpp"

namespace hydro::compiler
{
class Statement : public ASTNode
{
protected:
    Statement(AST *owner);

public:
    virtual ~Statement();
};

} // namespace hydro::compiler

#endif /* __h3o_Statement__ */
