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

#include "ElementDecorator.hpp"

namespace hydro::engine
{
ElementDecorator::ElementDecorator(ElementInstance *instance, Element *element)
    : InstanceDecorator{instance, element}
{
}

ElementDecorator::~ElementDecorator()
{
}

} // namespace hydro::engine
