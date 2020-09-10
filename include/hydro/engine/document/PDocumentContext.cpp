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

#include "PDocumentContext.hpp"

namespace hydro::engine
{

PDocumentContext::PDocumentContext()
{
    mParent = nullptr;
    mOwner = nullptr;
}

PDocumentContext::PDocumentContext(PDocumentContext *parent)
{
    mParent = parent;
    mOwner = nullptr;
}

PDocumentContext::~PDocumentContext()
{
}

bool PDocumentContext::contains(Symbol *symbol)
{
    if(!symbol->mContext)
    {
        for(auto sym : mSymbols)
            if(sym->compare(symbol))
                return true;
    }
    return symbol->mContext == this;
}

void PDocumentContext::define(Symbol *symbol)
{
    if(contains(symbol))
        return;
    mSymbols.push_back(symbol);
    symbol->mContext = this;
}

} // namespace hydro::engine
