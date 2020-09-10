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

#include "PrototypeSymbol.hpp"

namespace hydro::engine
{

PrototypeSymbol::PrototypeSymbol(std::string name) : Symbol{ name }
{
    mParent = nullptr;
}

PrototypeSymbol::~PrototypeSymbol()
{
}

bool PrototypeSymbol::compare(Symbol *symbol) const
{
    if(symbol == this)
        return true;
    if(auto prototype = dynamic_cast<PrototypeSymbol *>(symbol))
        if(getName() == prototype->getName())
            return true;
    return false;
}

} // namespace hydro::engine
