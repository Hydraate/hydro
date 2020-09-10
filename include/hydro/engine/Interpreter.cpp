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

#include "Interpreter.hpp"

namespace hydro::engine
{
Interpreter::Interpreter(CommandChain *commandChain)
{
    mCommandChain = commandChain;
    mPaused = mActive = false;
    mCurrentCommand = nullptr;
}

Interpreter::~Interpreter() {}

void Interpreter::run()
{
    mPaused = false;
    mActive = true;
    cpu();
}

void Interpreter::pause()
{
    // only pause if active
    mPaused = mActive;
}

void Interpreter::kill()
{
    mActive = mPaused = false;
    while (!mCommandChain->isEmpty())
        mCommandChain->nextCommand();
}

void Interpreter::opush(hvalue opnd)
{
    mOperandStack.push(opnd);
}

hvalue
Interpreter::opop()
{
    hvalue top = mOperandStack.top();
    mOperandStack.pop();
    return top;
}

hvalue
Interpreter::otop()
{
    return mOperandStack.top();
}

void Interpreter::cpu()
{
    // begin executing at current
    mCurrentCommand = mCommandChain->nextCommand();

    do
    {
        mCurrentCommand = execute(mCurrentCommand);
        if (!mCurrentCommand)
            mCurrentCommand = mCommandChain->nextCommand();
    } while (mCurrentCommand && mActive && !mPaused);

    // execution is complete or paused at this point
    mActive = mPaused;
}

std::shared_ptr<Command>
Interpreter::execute(std::shared_ptr<Command> cmd)
{
    hvalue a;
    hvalue b;

    switch (cmd->getType())
    {
        case exp_cmd:
        {
            b = opop();
            a = opop();
            opush(a.exp(b));
            break;
        };
        case mul_cmd:
        {
            b = opop();
            a = opop();
            opush(a * b);
            break;
        };
        case div_cmd:
        {
            b = opop();
            a = opop();
            opush(a / b);
            break;
        };
        case mod_cmd:
        {
            b = opop();
            a = opop();
            opush(a % b);
            break;
        };
        case add_cmd:
        {
            b = opop();
            a = opop();
            opush(a + b);
            break;
        };
        case sub_cmd:
        {
            b = opop();
            a = opop();
            opush(a - b);
            break;
        };
        case eq_cmd:
        {
            b = opop();
            a = opop();
            opush(a == b);
            break;
        };
        case ieq_cmd:
        {
            b = opop();
            a = opop();
            opush(a != b);
            break;
        };
        case alloc_cmd:
        {
            break;
        };
        case ptr_cmd:
        {
            // do nothing
            break;
        };
        case jmp_cmd:
        {
            BranchCommand *branch = static_cast<BranchCommand *>(cmd.get());
            return branch->getTarget();
            break;
        };
        case brt_cmd:
        {
            break;
        };
        case brf_cmd:
        {
            break;
        };
        default:
        {
            // error! unrecognized command
            break;
        }
    }

    return nullptr;
}

} // namespace hydro::engine
