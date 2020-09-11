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

#include "EventSymbol.hpp"

namespace hydro::engine
{

EventSymbol::EventSymbol(std::string name) : Symbol{ name }
{
}

EventSymbol::~EventSymbol()
{
}

bool EventSymbol::compare(Symbol *symbol) const
{
    if(symbol == this)
        return true;
    if(auto event = dynamic_cast<EventSymbol *>(symbol))
        if(getName() == event->getName())
            return true;
    return false;
}

} // namespace hydro::engine
