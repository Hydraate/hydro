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

#ifndef __h3o_FunctionDelegateSpecifier__
#define __h3o_FunctionDelegateSpecifier__

#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class FunctionDelegateSpecifier : public TypeSpecifier
{
public:
    FunctionDelegateSpecifier();
    virtual ~FunctionDelegateSpecifier();
};

} // namespace hydro::compiler

#endif /* __h3o_FunctionDelegateSpecifier__ */
