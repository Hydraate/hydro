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

#ifndef __h3o_engine_Engine__
#define __h3o_engine_Engine__

#include "document/PerformanceCompiler.hpp"

#include "Document.hpp"
#include "Interpreter.hpp"
#include "Performance.hpp"

namespace hydro::engine
{
/**
 * The Engine class provides an interface for loading and launching Performance documents.
 */
class Engine final
{
public:
    /**
     * Creates an Engine object.
     */
    Engine();

    /**
     * Destroys the Engine object.
     */
    ~Engine();
    
    /**
     * Loads a Performance document from a file.
     * @param pathToDocument pathToDocument The path to the (.pdoc) on disk.
     */
    void loadPerformanceFromFile(std::string pathToDocument);
    
    /**
     * Loads a Performance document from a string.
     * @param documentString The Performance document string in which to load the document.
     * @param pathToDocument An optional path that can be used to reference and identify the Performance document. This is normally a file path.
     */
    void loadPerformanceFromMemory(std::string documentString, std::string pathToDocument = "");

    /**
     * Starts the engine. If the engine is already active or a document context is not present, this method does nothing.
     */
    void start();

    /**
     * Stops the engine.
     */
    void stop();
    
    /**
     * Pauses the engine. The engine will still be considered active but not running.
     */
    void pause();
    
    /**
     * Resumes the engine if the engine is active and paused. Otherwise this method does nothing.
     */
    void resume();

    /**
     * Specifies whethor or not the engine is active. Calling the start() or stop() methods will affect the active state of the engine.
     * @return Returns true if the engine is running or paused. Otherwise returns false.
     */
    bool isActive() const { return mActive; }
    
    /**
     * Specifies whether or not the engine is actively running.
     * @return Returns true if the engine is running. Otherwise returns false.
     */
    bool isRunning() const { return mActive && !mPaused; }
    
    /**
     * Specifies whether or not the engine is paused. Calling the pause() and resume() methods affect the paused state of the engine.
     * @return Returns true if the engine is paused. Otherwise returns false. The engine will never be paused if it is not active.
     */
    bool isPaused() const { return mPaused; }
    
    /**
     * Gets the root document of the Performance.
     * @return Returns the Document instance that was generated from a source as a result of calling loadPerformanceFromFile() or loadPerformanceFromMemory(). Returns null if the document was not supplied or non-existent.
     */
    const Document *getDocument() const { return mDocument; }
    
private:
    /**
     * The root document of the performance.
     */
    Document *mDocument;
    
    /**
     * Stores the active state of the engine.
     */
    bool mActive;
    
    /**
     * Stores the paused state of the engine.
     */
    bool mPaused;
    
    /**
     * The interpreter to use in order to execute instructions.
     */
    Interpreter *mInterpreter;

    /**
     * The command chain that represents the set of instructions to execute within the environment.
     */
    CommandChain *mCommandChain;
    
    
    /**
     * Builds a Performance.
     * @param document The generated document in which to build.
     */
    bool buildPerformance(Document *document)
    {
        
        return false;
    }
    
    /**
     * Runs the pipeline such that a result is produced by the engine.
     */
    inline void run();
};

} // namespace hydro::engine

#endif /* __h3o_engine_Engine__ */
