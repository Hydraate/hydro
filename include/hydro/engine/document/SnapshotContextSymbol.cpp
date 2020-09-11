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

#include "SnapshotContextSymbol.hpp"

namespace hydro::engine
{

SnapshotContextSymbol::SnapshotContextSymbol(std::string name) : Symbol{ name }
{
}

SnapshotContextSymbol::~SnapshotContextSymbol()
{
}

bool SnapshotContextSymbol::compare(Symbol *symbol) const
{
    if(symbol == this)
        return true;
    if(auto context = dynamic_cast<SnapshotContextSymbol *>(symbol))
        if(getName() == context->getName())
            return true;
    return false;
}

} // namespace hydro::engine
