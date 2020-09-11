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

#ifndef __h3o_engine_Command__
#define __h3o_engine_Command__

#include <cstdlib>
#include <memory>

namespace hydro::engine
{
class CommandChain;

/**
 * The Command class represents an instruction or set of instructions ensapsulated inside of an object.
 * @author Jaron Fort
 */
class Command
{
public:
    /**
     * Creates a Command object using the command type represented by an unsigned 16-bit integer.
     */
    Command(uint16_t type);

    /**
     * Destroys the Command object.
     */
    virtual ~Command();

    /**
     * Gets the type associated with this command.
     */
    uint16_t getType() const { return mType; }

    /**
     * Clones the command.
     * @return Returns a copy of the command instance.
     */
    virtual std::shared_ptr<Command> clone() const;

    /**
     * Gets the previous command in the command chain.
     * @return Returns the command that comes before the command instance in the command chain or null if the command instance is the first command in the chain.
     */
    std::shared_ptr<Command> getPrev() const { return mPrev; }

    /**
     * Gets the next command in the command chain.
     * @return Returns the command that follows the command instance in the command chain or null if the command instance is the last command in the chain.
     */
    std::shared_ptr<Command> getNext() const { return mNext; }

    /**
     * Specifies whether or not the command is the first in the command chain.
     * @return Returns true if the command is the first command in the command chain. Otherwise returns false.
     */
    bool isFirst() const { return mPrev == nullptr; }

    /**
     * Specifies whether or not the command is the last command in the comand chain.
     * @return Returns true if the command is the last command in the command chain. Otherwise returns false.
     */
    bool isLast() const { return mNext == nullptr; }

private:
    /**
     * The command type for the command.
     */
    uint16_t mType;

    /**
     * The previous command in the command chain if exists.
     */
    std::shared_ptr<Command> mPrev;

    /**
     * The next command in teh comamnd chain if exists.
     */
    std::shared_ptr<Command> mNext;

    friend class CommandChain;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Command__ */
