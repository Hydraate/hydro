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

#ifndef __h3o_Binding__
#define __h3o_Binding__

#include "Name.hpp"

namespace hydro::compiler
{
class BindingResolver;

class Binding
{
protected:
    Binding();

public:
    virtual ~Binding();
    virtual Name *getName() const = 0;
    virtual BindingResolver *getBindingResolver() const = 0;
};

} // namespace hydro::compiler

#endif /* __h3o_Binding__ */
