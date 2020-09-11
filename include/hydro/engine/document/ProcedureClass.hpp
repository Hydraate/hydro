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

#ifndef __h3o_engine_ProcedureClass__
#define __h3o_engine_ProcedureClass__

#include "EntityType.hpp"

namespace hydro::engine
{
/**
 * The Procedure class represents a procedure context. This class is necessary to resolve and bind procedure entities to potentially native abstractions or to define procedures within a scoped context.
 */
class ProcedureClass final : public EntityType
{
public:
    /**
     * Creates a Procedure object with a name.
     */
    ProcedureClass(Name *name);

    /**
     * Destroyes the Procedure object.
     */
    virtual ~ProcedureClass();
    
    /**
     * Accepts a visitor allowing the visitor to visit the procedure class.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureClass__ */
