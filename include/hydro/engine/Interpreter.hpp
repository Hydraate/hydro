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

#ifndef __h3o_engine_Interpreter__
#define __h3o_engine_Interpreter__

#include <stack>

#include "../vm/hvalue.hpp"
#include "command/CommandChain.hpp"

namespace hydro::engine
{
/**
 * The Interpreter class executes instructions within the engine in order to manipute objects in the Hydro environment.
 */
class Interpreter
{
public:
    /**
     * Creates an Interpreter object using a single command chain.
     */
    Interpreter(CommandChain *commandChain);

    /**
     * Destructor for the interpreter.
     */
    virtual ~Interpreter();

    /**
     * Runs the interpreter. If the interpreter is paused, the interpreter is resumed. All commands are executed until the intepreter is paused, killed, or all commands have been executed leaving the command chain empty and all processes are completed.
     */
    void run();

    /**
     * Pauses the interpreter if the interpreter is active.
     */
    void pause();

    /**
     * Kills the interpreter stopping execution.
     */
    void kill();

    /**
     * Specifies whether or not the interpreter is actively executing command instructions.
     * @return Returns true if the interpreter is active. Otherwise returns false.
     */
    bool isActive() const { return mActive; }

    /**
     * Specifies whether or not the interpreter is paused.
     * @return Returns true if the interpreter is paused. Otherwise returns false.
     */
    bool isPaused() const { return mPaused; }

protected:
    /**
     * Pushes an operand onto the operand stack.
     * @param opnd The operand in which to push.
     */
    void opush(hvalue opnd);

    /**
     * Gets and pops the top of the operand stack.
     * @return Returns the top operand before the stack is popped.
     */
    hvalue opop();

    /**
     * Gets the operand on the top of the operand stack.
     * @return Returns the top operand.
     */
    hvalue otop();

    /**
     * Loads commands from the command chain and executes them.
     */
    void cpu();

    /**
     * Executes a command. This method may be overriden to support additional commands. This method is also inline to avoid stack overload.
     * @param cmd The command in which to execute.
     * @return May return a command that should be executed next to simulate a jump instruction. If returned null the cpu() method will execute the next command in the command chain from the current command.
     */
    virtual inline std::shared_ptr<Command> execute(std::shared_ptr<Command> cmd);

private:
    /**
     * Stores the "paused" state of the interpreter.
     */
    bool mPaused;

    /**
     * Stores the "active" state of the interpreter.
     */
    bool mActive;

    /**
     * The stack storing operands used during execution.
     */
    std::stack<hvalue> mOperandStack;

    /**
     * The current command that will execute next or is currently executing.
     */
    std::shared_ptr<Command> mCurrentCommand;

    /**
     * The command chain that stores all commands required for a particular execution run.
     */
    CommandChain *mCommandChain;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Interpreter__ */
