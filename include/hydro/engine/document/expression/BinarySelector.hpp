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

#ifndef __h3o_engine_BinarySelector__
#define __h3o_engine_BinarySelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The abstract CompoundSelector class is the base class for all compound selector types.
 */
class CompoundSelector final : public Selector
{
protected:
    /**
     *
     */
    CompoundSelector(Selector *lhs, compiler::Token token, Selector *rhs);

public:
    /**
     *
     */
    virtual ~CompoundSelector();
};

} // namespace hydro::engine


#endif /* BinarySelector_hpp */
