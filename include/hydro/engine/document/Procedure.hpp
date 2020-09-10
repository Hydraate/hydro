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

#ifndef __h3o_engine_Procedure__
#define __h3o_engine_Procedure__

#include "Entity.hpp"
#include "ProcedureIdentity.hpp"

namespace hydro::engine
{
/**
 * The Procedure class represents a procedure entity in a document. Procedures decribe callable sections of the document.
 */
class Procedure : public Entity
{
public:
    /**
     * Creates a Procedure object that is a child of some entity.
     */
    Procedure(Entity *parent, ProcedureIdentity *identity);

    /**
     * Destroys the Procedure object.
     */
    virtual ~Procedure();

    /**
     * Accepts a visitor allowing the visitor to visit the procedure entity.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_Procedure__ */
