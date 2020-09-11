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

#include "ActionSymbol.hpp"

namespace hydro::engine
{

ActionSymbol::ActionSymbol(std::string name) : Symbol{ name }
{
}

ActionSymbol::~ActionSymbol()
{
}

bool ActionSymbol::compare(Symbol *symbol) const
{
    if(symbol == this)
        return true;
    if(auto action = dynamic_cast<ActionSymbol *>(symbol))
        if(getName() == action->getName())
            return true;
    return false;
}

} // namespace hydro::engine
