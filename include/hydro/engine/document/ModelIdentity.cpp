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

#include "ModelIdentity.hpp"

namespace hydro::engine
{

ModelIdentity::ModelIdentity(ModelDescription *description) : Identity{ description }
{
}

ModelIdentity::~ModelIdentity()
{
}

} // namespace hydro::engine
