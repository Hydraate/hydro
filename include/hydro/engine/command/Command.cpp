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

#include "Command.hpp"

namespace hydro::engine
{
Command::Command(uint16_t type)
{
    mType = type;
}

Command::~Command() {}

std::shared_ptr<Command>
Command::clone() const
{
    return std::shared_ptr<Command>{new Command{mType}};
}

} // namespace hydro::engine
