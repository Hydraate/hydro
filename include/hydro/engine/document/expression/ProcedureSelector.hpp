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

#ifndef __h3o_engine_ProcedureQualifier__
#define __h3o_engine_ProcedureQualifier__

#include "../ProcedureClass.hpp"

#include "EntitySelector.hpp"

namespace hydro::engine
{
/**
 * The ProcedureSelector class provides a selector that targets procedures.
 */
class ProcedureSelector final : public EntitySelector
{
public:
    /**
     * Creates a ProcedureSelector with a procedure class.
     * @param type The procedure class.
     */
    ProcedureSelector(ProcedureClass *type);

    /**
     * Destroys the ProcedureSelector object.
     */
    virtual ~ProcedureSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the procedure selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_ProcedureQualifier__ */
