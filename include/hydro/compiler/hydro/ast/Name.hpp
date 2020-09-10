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

#ifndef __h3o_internal_Name__
#define __h3o_internal_Name__

#include "../../Token.hpp"
#include "ASTNode.hpp"

namespace hydro::compiler
{
class Name : public ASTNode
{
public:
    Name(AST *owner);
    virtual ~Name();
    virtual std::string getValue() const = 0;
    virtual bool isSimpleName() const = 0;
    virtual bool isQualifiedName() const = 0;
    virtual bool compare(Name *name) const = 0;
};

} // namespace hydro::compiler

#endif /* __h3o_internal_Name__ */
