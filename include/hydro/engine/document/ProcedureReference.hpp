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

#include "ProcedureClass.hpp"
#include "SimpleReference.hpp"

namespace hydro::engine
{
/**
 * The ProcedureReference class represents a reference to a procedure entity defined in a document.
 */
class ProcedureReference final : public SimpleReference
{
public:
    /**
     * Creates a ProcedureReference object that represents a reference to a procedure.
     * @param _class The procedure class.
     */
    ProcedureReference(ProcedureClass *_class);

    /**
     * Detroys the ProcedureReference object.
     */
    virtual ~ProcedureReference();
    
    /**
     * Accepts a visitor allowing the visitor to visit the procedure target.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureReference__ */
