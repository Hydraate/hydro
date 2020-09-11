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

#include "BranchCommand.hpp"

namespace hydro::engine
{
/**
 *
 */
BranchCommand::BranchCommand(uint16_t type)
    : Command{type}
{
    mTarget = nullptr;
}

/**
 *
 */
BranchCommand::BranchCommand(uint16_t type, std::shared_ptr<Command> target)
    : Command{type}
{
    mTarget = target;
}

/**
 *
 */
BranchCommand::~BranchCommand() {}

/**
 *
 */
std::shared_ptr<Command>
BranchCommand::clone() const
{
    return std::shared_ptr<Command>{new BranchCommand{getType(), mTarget}};
}

} // namespace hydro::engine
