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

#ifndef __h3o_Declaration__
#define __h3o_Declaration__

#include "Modifiers.hpp"

namespace hydro::compiler
{
class Declaration
{
protected:
    Declaration();

public:
    Modifiers *modifiers;
    virtual ~Declaration();
};

} // namespace hydro::compiler

#endif /* __h3o_Declaration__ */
