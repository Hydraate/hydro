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

#ifndef __h3o_internalmCompiler__
#define __h3o_internalmCompiler__

#include "ErrorReporter.hpp"
#include "SourceManager.hpp"

#define HVM_DEFAULT_COMPILATION_ERROR_CAP 32

namespace hydro::compiler
{
/**
 *
 */
struct CompilerOptions
{
    /**
     *
     */
    uint32_t maxErrors;
};

/**
 *
 */
class Compiler
{
protected:
    /**
     *
     */
    Compiler();

    /**
     *
     */
    Compiler(CompilerOptions options);

public:
    /**
     *
     */
    virtual ~Compiler();

    /**
     *
     */
    void abort() { mActive = false; }

    /**
     *
     */
    void compileFromString(std::string inputData, std::string sourceLocation);

    /**
     *
     */
    bool compileFromFile(std::string filepath);

    /**
     *
     */
    SourceManager *sourceManager() const { return mSourceManager; }

    /**
     *
     */
    ErrorReporter *errorReporter() const { return mErrorReporter; }

    /**
     *
     */
    bool errorDidOccur() const { return mErrorReporter ? mErrorReporter->numErrors() > 0 : false; }

    /**
     *
     */
    uint32_t maxErrors() const { return mMaxErrors; }

protected:
    /**
     * The maximum number of errors that may occur before the compiler aborts. Does not include warnings.
     */
    uint32_t mMaxErrors;

    /**
     * The source manager.
     */
    SourceManager *mSourceManager;

    /**
     * The error reporter.
     */
    ErrorReporter *mErrorReporter;

    /**
     *
     */
    bool mActive;

    /**
     *
     */
    bool mInit;

    /**
     *
     */
    virtual void setup();

    /**
     *
     */
    virtual void compileSource(SourceBuffer *input) = 0;

    /**
     *
     */
    virtual SourceManager *createSourceManager();

    /**
     *
     */
    virtual ErrorReporter *createErrorReporter();
};

} // namespace hydro::compiler

#endif /* __h3omCompiler__ */
