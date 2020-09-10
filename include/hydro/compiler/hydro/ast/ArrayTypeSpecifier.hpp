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

#ifndef __h3o_ArrayTypeSpecifier__
#define __h3o_ArrayTypeSpecifier__

#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class ArrayTypeSpecifier final : public TypeSpecifier
{
public:
    TypeSpecifier *typeSpecifier;
    ArrayTypeSpecifier(AST *owner);
    virtual ~ArrayTypeSpecifier();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ArrayTypeSpecifier__ */
