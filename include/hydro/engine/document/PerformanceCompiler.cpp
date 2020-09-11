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

#include "PerformanceCompiler.hpp"

namespace hydro::engine
{
PerformanceCompiler::PerformanceCompiler()
{
    mParser = nullptr;
}

PerformanceCompiler::~PerformanceCompiler()
{
    delete mParser;
}

void PerformanceCompiler::compileSource(compiler::SourceBuffer *buffer)
{
    if (!mParser)
        mParser = new PDocumentParser{ errorReporter() };
    mParser->parse(buffer);
}

} // namespace hydro::engine
