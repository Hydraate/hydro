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

#ifndef __h3o_engine_Performance__
#define __h3o_engine_Performance__

#include "Document.hpp"
#include "Instance.hpp"

namespace hydro::engine
{
/**
 * The Performance class provides a top level manifestation of a document as a physical instance. The Performance is the highest level instance that is allocated and managed by the engine.
 */
class Performance final : public Instance
{
private:
    /**
     * Creates a Performance object that is owned by particular engine.
     * @param document The document that will be rendered by the Performance.
     */
    Performance(Engine *engine, Document *document);

public:
    /**
     * Destroys the Performance object.
     */
    ~Performance();
    
    /**
     * Creates a Performance object that is owned by some engine and renders some document.
     * @param engine The engine that owns the Performance.
     * @param document The document that will be rendered by the Performance.
     * @return Returns the newly created Performance object.
     */
    static Performance *create(Engine *engine, Document *document) { return new Performance{ engine, document }; }
    
    /**
     * Gets the Performance document.
     * @return Returns the Document instance that will be rendered by the Peformance.
     */
    const Document *getDocument() const { return mDocument; }
    
private:
    /**
     * The Performance document.
     */
    Document *mDocument;
};

} // namespace hydro::engine

#endif /* __h3o_engine_Performance__ */
