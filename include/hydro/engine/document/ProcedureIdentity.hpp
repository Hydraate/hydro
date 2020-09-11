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

#ifndef __h3o_engine_ProcedureIdentity__
#define __h3o_engine_ProcedureIdentity__

#include "Identity.hpp"
#include "ProcedureClass.hpp"

namespace hydro::engine
{
/**
 * The ProcedureIdentity class stores information about the identity of a procedure entity in a Performance document.
 */
class ProcedureIdentity final : public Identity
{
public:
    /**
     * Creates a ProcedureIdentity object with relationships and a procedure class.
     */
    ProcedureIdentity(IdentityRelationshipsList *relationships, ProcedureClass *type);

    /**
     * Destroys the ProcedureIdentity object.
     */
    virtual ~ProcedureIdentity();
    
    /**
     * Accepts a visitor allowing the visitor to visit the procedure identity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureIdentity__ */
