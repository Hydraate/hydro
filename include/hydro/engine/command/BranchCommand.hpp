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

#ifndef __h3o_engine_BranchCommand__
#define __h3o_engine_BranchCommand__

#include "Command.hpp"

namespace hydro::engine
{
/**
 * The BranchCommand class implements a command intended to branch off to another command as in a jump instruction.
 */
class BranchCommand : public Command
{
public:
    /**
     * Creates a BranchCommand object using a command type and relies on late initialization of the target command (normally because of a forward reference).
     */
    BranchCommand(uint16_t type);

    /**
     * Creates a BranchCommand object using a command type and a target command.
     */
    BranchCommand(uint16_t type, std::shared_ptr<Command> target);
    virtual ~BranchCommand();

    /**
     * Clones the BranchCommand.
     * @return Returns a copy of the command.
     */
    virtual std::shared_ptr<Command> clone() const override;

    /**
     * Gets the command target.
     * @return Returns the target command if it is set. Otherwise returns null.
     */
    std::shared_ptr<Command> getTarget() const { return mTarget; }

    /**
     * Sets the target command.
     * @param target The target command.
     */
    void setTarget(std::shared_ptr<Command> target) { mTarget = target; }

    /**
     * Specifies whether or not the target has been set.
     */
    bool hasTarget() const { return mTarget != nullptr; }

protected:
    /**
     *
     */
    std::shared_ptr<Command> mTarget;
};

} // namespace hydro::engine

#endif /* __h3o_engine_BranchCommand__ */
