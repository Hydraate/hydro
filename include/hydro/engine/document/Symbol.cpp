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

#include "Symbol.hpp"

namespace hydro::engine
{

Symbol::Symbol()
{
    mContext = nullptr;
}

Symbol::Symbol(std::string name)
{
    mName = name;
}

Symbol::~Symbol()
{
}

} // namespace hydro::engine
