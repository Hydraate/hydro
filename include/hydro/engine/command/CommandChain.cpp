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

#include "CommandChain.hpp"

namespace hydro::engine
{
CommandChain::CommandChain()
{
}

CommandChain::~CommandChain()
{
}

std::shared_ptr<Command>
CommandChain::nextCommand()
{
    if (mCurrent)
    {
        const std::shared_ptr<Command> current = mCurrent;
        mCurrent = current->getNext();
        if (current == mEnd)
            mEnd = mCurrent = nullptr; // reset (end of chain)
        return current;
    }

    // empty
    return nullptr;
}

void CommandChain::addPower()
{
    create(exp_cmd);
}

void CommandChain::addMultiply()
{
    create(mul_cmd);
}

void CommandChain::addDivide()
{
    create(div_cmd);
}

void CommandChain::addModulo()
{
    create(mod_cmd);
}

void CommandChain::addAdd()
{
    create(add_cmd);
}

void CommandChain::addSubtract()
{
    create(sub_cmd);
}

void CommandChain::addEquality()
{
    create(eq_cmd);
}

void CommandChain::addInequality()
{
    create(ieq_cmd);
}

std::shared_ptr<Command>
CommandChain::addPlaceholder()
{
    return create(ptr_cmd);
}

void CommandChain::insert(std::shared_ptr<Command> cmd)
{
    if (mEnd)
    {
        mEnd = mCurrent = cmd;
        cmd->mPrev = cmd->mNext = nullptr;
        return;
    }

    std::shared_ptr<Command> prev = mCurrent;
    mCurrent = cmd;
    mCurrent->mPrev = prev;
    mCurrent->mNext = nullptr;
}

} // namespace hydro::engine
