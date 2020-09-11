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

#include "QueryTarget.hpp"

namespace hydro::engine
{

QueryTarget::QueryTarget(Selector *selector) : Target{}
{
    mSelector = selector;
}

QueryTarget::~QueryTarget()
{
    delete mSelector;
}

} // namespace hydro::engine
