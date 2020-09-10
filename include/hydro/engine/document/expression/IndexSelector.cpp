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

#include "IndexSelector.hpp"

namespace hydro::engine
{

IndexSelector::IndexSelector(Selector *subject, Expression *index)
{
    mSubject = subject;
    mIndex = index;
}

IndexSelector::~IndexSelector()
{
}

} // namespace hydro::engine
