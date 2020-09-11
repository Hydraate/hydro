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

#ifndef __h3o_ErrorReporter__
#define __h3o_ErrorReporter__

#include <string>
#include <vector>

#include "Line.hpp"
#include "Token.hpp"

namespace hydro::compiler
{
class Compiler;

/**
 * The ErrorReporter class stores errors and warnings produced by compiler components.
 */
class ErrorReporter
{
public:
    /**
     * Creates an ErrorReporter object that is owned by some compiler.
     * @param compiler The compiler owner.
     */
    ErrorReporter(Compiler *compiler);
    
    /**
     * Destroys the ErrorReporter object.
     */
    ~ErrorReporter();
    
    /**
     * Reports an error using a source position.
     * @param errorText The error message text.
     * @param pos The source position that represents the region of a file where the error takes place.
     */
    void reportError(std::string errorText, SourcePosition pos);
    
    /**
     * Reports an error using a token.
     * @param errorText The error message text.
     * @param erroneousToken The erroroneous token.
     */
    void reportError(std::string errorText, Token erroneousToken);
    
    /**
     * Reports an error as a warning using a source position.
     * @param errorText The error message text.
     * @param pos The source position that represents the region of a file where the error takes place.
     */
    void reportWarning(std::string errorText, SourcePosition pos);
    
    /**
     * Reports an error as a warning using a token.
     * @param errorText The error message text.
     * @param erroneousToken The erroroneous token.
     */
    void reportWarning(std::string errorText, Token erroneousToken);

    /**
     * Gets the compiler that owns this error reporter.
     */
    Compiler *getCompiler() const { return mCompiler; }
    
    /**
     * Gets the number of errors and warnings contained within the error reporter.
     */
    uint32_t numErrorsAndWarnings() const { return (uint32_t)mErrors.size(); }
    
    /**
     * Gets the number of errors contained within the error reporter. Excludes warnings.
     */
    uint32_t numErrors() const { return mNumErrors; }
    
    /**
     * Computes the number of errors in a given source. Excludes warnings.
     */
    uint32_t numErrors(const SourceID &source) const;
    
    /**
     * Gets the number of warnings contained within the error reporter. Excludes errors.
     */
    uint32_t numWarnings() const { return mNumWarnings; }
    
    /**
     * Computes the number of warnings in a given source. Excludes errors.
     */
    uint32_t numWarnings(const SourceID &source) const;
    
    /**
     * Computes the number of errors and warnings in a given source.
     */
    uint32_t numErrorsAndWarnings(const SourceID &source) const;
    
    /**
     * Specifies whether or not the error reporter contains errors.
     * @return Returns true if the error reporter does not contain errors. Otherwise returns false.
     */
    bool isEmpty() const { return mErrors.empty(); }
    
    /**
     * Gets the index of an error at a given source position.
     */
    int32_t errorIndexAtPosition(const SourcePosition &pos) const;
    
    /**
     *
     */
    std::string errorText(std::size_t index) const { return mErrors[index]->errorText; }
    
    /**
     *
     */
    std::string errorText(const SourcePosition &pos) const;
    
    /**
     *
     */
    const SourcePosition position(std::size_t index) const { return mErrors[index]->pos; }
    
    /**
     *
     */
    bool isError(std::size_t index) const { return mErrors[index]->status == error_status::error; }
    
    /**
     *
     */
    bool isWarning(std::size_t index) const { return mErrors[index]->status == error_status::warning; }

protected:
    /**
     *
     */
    enum class error_status
    {
        error,
        warning
    };
    
    /**
     *
     */
    struct compilation_error
    {
        std::string errorText;
        SourcePosition pos;
        error_status status;
    };
    
    /**
     *
     */
    std::vector<compilation_error *> mErrors;
    
    /**
     *
     */
    Compiler *mCompiler;
    
    /**
     *
     */
    uint32_t mNumErrors, mNumWarnings;
};

} // namespace hydro::compiler

#endif /* __h3o_ErrorReporter__ */
