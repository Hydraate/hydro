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

#include "terminal_format.hpp"

namespace hydro
{

std::ostream &operator<<(std::ostream &lhs, const terminal_format &rhs)
{
    lhs << rhs.value();
    return lhs;
}

} // namespace hydro
