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

#ifndef __h3o_engine_PerformanceCompiler__
#define __h3o_engine_PerformanceCompiler__

#include "../../compiler/Compiler.hpp"

#include "PDocumentParser.hpp"

namespace hydro::engine
{
/**
 * The PerformanceCompiler class is responsible for parsing and building a Performance for a Performance document. The inherited Compiler class automatically provides useful members such as an error reporter and source manager to assist in the compilation process.
 */
class PerformanceCompiler final : public compiler::Compiler
{
public:
    /**
     * Creates a PerformanceCompiler object.
     */
    PerformanceCompiler();

    /**
     * Destroys the PerformanceCompiler object.
     */
    virtual ~PerformanceCompiler();

protected:
    /**
     * The parser that will parse the source buffer.
     */
    PDocumentParser *mParser;

    /**
     * Runs the parser and builds a Performance document.
     * @param buffer The source buffer in which to compile.
     */
    virtual void compileSource(compiler::SourceBuffer *buffer) override;
};

} // namespace hydro::engine

#endif /* __h3o_engine_PerformanceCompiler__ */
