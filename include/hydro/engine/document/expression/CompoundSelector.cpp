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

#include "CompoundSelector.hpp"


namespace hydro::engine
{

CompoundSelector::CompoundSelector(Selector *subject, Selector *target) : Selector{}
{
}

CompoundSelector::~CompoundSelector()
{
}

Selector *CompoundSelector::getTop() const
{
    if(CompoundSelector *compound = dynamic_cast<CompoundSelector *>(mSubject))
        return compound->getTop();

    // the subject is the top selector
    return mSubject;
}

} // namespace hydro::engine
