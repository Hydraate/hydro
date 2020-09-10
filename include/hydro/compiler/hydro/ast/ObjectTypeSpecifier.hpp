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

#ifndef __h3o_ObjectTypeSpecifier__
#define __h3o_ObjectTypeSpecifier__

#include "Name.hpp"
#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class ObjectTypeSpecifier : public TypeSpecifier
{
public:
    Name *subject;

    ObjectTypeSpecifier(AST *owner);
    virtual ~ObjectTypeSpecifier();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_ObjectTypeSpecifier__ */
