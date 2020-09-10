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

#ifndef __h3o_engine_PDocumentPrinter__
#define __h3o_engine_PDocumentPrinter__

#include <iostream>

#include "DocumentVisitor.hpp"

namespace hydro::engine
{
/**
 * The PDocumentPrinter class writes a document representation to an output stream.
 */
class PDocumentPrinter : public DocumentVisitor
{
public:
    /**
     * Creates a PDocumentPrinter object with an output stream.
     */
    PDocumentPrinter(std::ostream &out);
    
    /**
     * Destroys the PDocumentPrinter object.
     */
    virtual ~PDocumentPrinter();
    
    /**
     * Gets the output stream that the printer writes to.
     */
    const std::ostream &getOutputStream() const { return mOut; }
    
protected:
    /**
     * The outut stream.
     */
    std::ostream &mOut;
};

} // namespace hydro::engine

#endif /* __h3o_engine_PDocumentPrinter__ */
