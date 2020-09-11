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

#ifndef __h3o_engine_Subject__
#define __h3o_engine_Subject__

#include <regex>
#include <string>

#include "Node.hpp"

namespace hydro::engine
{
/**
 * The abstract Subject class is base class of all subject types. Subjects are the segments of a entity's identity that refer to a class, contain a query, or point to a single entity.
 */
class Subject : public Node
{
protected:
    /**
     * Creates a Subject object.
     */
    Subject();

public:
    /**
     * Destroys the Subject object.
     */
    virtual ~Subject();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Subject__ */
