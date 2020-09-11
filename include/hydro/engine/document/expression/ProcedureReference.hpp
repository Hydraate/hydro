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

#ifndef __h3o_engine_ProcedureReference__
#define __h3o_engine_ProcedureReference__

#include "../Name.hpp"
#include "Expression.hpp"

namespace hydro::engine
{
class ProcedureQualifier final : public Expression
{
public:
    /**
     *
     */
    ProcedureQualifier(Name *name);

    /**
     *
     */
    virtual ~ProcedureQualifier();

    /**
     *
     */
    Name *getName() const { return mName; }

private:
    /**
     *
     */
    Name *mName;
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureReference__ */
