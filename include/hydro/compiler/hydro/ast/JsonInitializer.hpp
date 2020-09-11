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

#ifndef __h3o_JsonInitializer__
#define __h3o_JsonInitializer__

#include "Expression.hpp"
#include "JsonMember.hpp"

namespace hydro::compiler
{
class JsonInitializer : public Expression
{
public:
    JsonInitializer(AST *owner);
    virtual ~JsonInitializer();
    virtual void accept(ASTVisitor *visitor) override;
};

} // namespace hydro::compiler

#endif /* __h3o_JsonInitializer__ */
