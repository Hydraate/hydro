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

#ifndef __h3o_engine_DocumentSelector__
#define __h3o_engine_DocumentSelector__

#include "Selector.hpp"

namespace hydro::engine
{

/**
 * The DocumentSelector class represents a self selector in a Performance document.
 */
class DocumentSelector final : public Selector
{
public:
    /**
     * Creates a DocumentSelector object with a token.
     */
    DocumentSelector(compiler::Token token);
    
    /**
     * Destroys the DocumentSelector object.
     */
    virtual ~DocumentSelector();
    
    /**
     * Accepts a visitor allowing the visitor to visit the document selector.
     * @param visitor The visitor to accept.
     */
    virtual void accept(DocumentVisitor *visitor) override { visitor->visit(this); }
};

} // namespace hydro::engine

#endif /* __h3o_engine_DocumentSelector__ */
