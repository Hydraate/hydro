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

#include "Model.hpp"

namespace hydro::engine
{

Model::Model(Entity *parent, ModelIdentity *identity) : Entity{ parent, identity }
{
}

Model::~Model()
{
}

} // namespace hydro::engine
