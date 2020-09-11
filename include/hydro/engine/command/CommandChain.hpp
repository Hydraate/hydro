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

#ifndef __h3o_engine_CommandChain__
#define __h3o_engine_CommandChain__

#include <list>
#include <memory>

#include "BranchCommand.hpp"
#include "command_type.hpp"

namespace hydro::engine
{
/**
 * The CommandChain class is a FIFO (first-in-first-out) structure for creating and propagating a chain of commands. This class is a factory for all command types and can be subclassed to add additional commands.
 */
class CommandChain
{
public:
    /**
     * Creates the CommandChain object.
     */
    CommandChain();

    /**
     * Destroys the CommandChain object.
     */
    virtual ~CommandChain();

    /**
     * Assists in the propagation of the command chain returning the front command. This method pops front of the chain.
     */
    std::shared_ptr<Command> nextCommand();

    /**
     * Creates an exponential command and inserts it into the chain.
     */
    void addPower();

    /**
     * Creates a multiplication command and inserts it into the chain.
     */
    void addMultiply();

    /**
     * Creates a division command and inserts it into the chain.
     */
    void addDivide();

    /**
     * Creates a modulo command and inserts it into the chain.
     */
    void addModulo();

    /**
     * Creates an addition command and inserts it into the chain.
     */
    void addAdd();

    /**
     * Creates a subtraction command and inserts it into the chain.
     */
    void addSubtract();

    /**
     * Creates an equality command and inserts it into the chain.
     */
    void addEquality();

    /**
     * Creates an inequality command and inserts it into the chain.
     */
    void addInequality();

    /**
     * Creates a placeholder command and inserts it into the chain.
     */
    std::shared_ptr<Command> addPlaceholder();

    /**
     * Gets the end of the command chain if it exists. Otherwise returns null.
     */
    std::shared_ptr<Command> getEnd() const { return mEnd; }

    /**
     * Specifies whether or not the command chain is empty.
     */
    bool isEmpty() const { return mEnd == nullptr; }

protected:
    /**
     * Inserts a command into the command chain.
     */
    void insert(std::shared_ptr<Command> cmd);

    /**
     * Creates a standard command with a command type that is similar to an opcode.
     */
    std::shared_ptr<Command> create(uint16_t type)
    {
        return create<Command>(type);
    }

    /**
     * Creates a command of a particular type.
     */
    template <typename T, typename... Args>
    std::shared_ptr<Command> create(uint16_t type, Args... args)
    {
        // assert that T is a command type.
        static_assert(std::is_base_of<Command, T>::value, "Template type must derive from hydro::engine::Command.");

        std::shared_ptr<Command> cmd{new T{type, args...}};
        insert(cmd);
        return cmd;
    }

private:
    /**
     * Points to the next command that will be returned by the nextCommand() method.
     */
    std::shared_ptr<Command> mCurrent;

    /**
     * Points to the last command that has entered the chain.
     */
    std::shared_ptr<Command> mEnd;
};

} // namespace hydro::engine

#endif /* __h3o_engine_CommandChain__ */
