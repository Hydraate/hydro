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

#ifndef __h3o_TypeSpecifier__
#define __h3o_TypeSpecifier__

#include "ASTNode.hpp"

namespace hydro::compiler
{
class TypeSpecifier : public ASTNode
{
protected:
    TypeSpecifier(AST *owner);

public:
    virtual ~TypeSpecifier();
};

} // namespace hydro::compiler

#endif /* __h3o_TypeSpecifier__ */
