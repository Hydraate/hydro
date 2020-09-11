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

#include "ElementID.hpp"

namespace hydro::engine
{

ElementID::ElementID(compiler::Token token) : Node{ token }
{
    std::string value = token.value();
    if(!value.empty() && value[0] == '@')
        value = value.substr(1); // omit @
    mValue = value;
}

ElementID::~ElementID()
{
}

} // namespace hydro::engine
