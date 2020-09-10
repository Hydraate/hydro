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

#include "ProcedureSymbol.hpp"

namespace hydro::engine
{

ProcedureSymbol::ProcedureSymbol(std::string name) : Symbol{ name }
{
}

ProcedureSymbol::~ProcedureSymbol()
{
}

bool ProcedureSymbol::compare(Symbol *symbol) const
{
    if(symbol == this)
        return true;
    if(auto procedure = dynamic_cast<ProcedureSymbol *>(symbol))
        if(getName() == procedure->getName())
            return true;
    return false;
}

} // namespace hydro::engine
