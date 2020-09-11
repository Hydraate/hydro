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

#ifndef __h3o_MultiTypeSpecifier__
#define __h3o_MultiTypeSpecifier__

#include "TypeSpecifier.hpp"

namespace hydro::compiler
{
class MultiTypeSpecifier : public TypeSpecifier
{
public:
    MultiTypeSpecifier();
    virtual ~MultiTypeSpecifier();
};

} // namespace hydro::compiler

#endif /* __h3o_MultiTypeSpecifier__ */
