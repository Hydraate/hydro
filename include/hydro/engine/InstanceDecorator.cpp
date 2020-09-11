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

#include "InstanceDecorator.hpp"

namespace hydro::engine
{
InstanceDecorator::InstanceDecorator(Instance *instance, Entity *entity)
{
    mInstance = instance;
    mEntity = entity;
}

InstanceDecorator::~InstanceDecorator()
{
}

} // namespace hydro::engine
