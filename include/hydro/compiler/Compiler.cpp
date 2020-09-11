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

#include "Compiler.hpp"

namespace hydro::compiler
{
Compiler::Compiler() : Compiler{{HVM_DEFAULT_COMPILATION_ERROR_CAP}}
{
}

Compiler::Compiler(CompilerOptions options)
{
    mMaxErrors = options.maxErrors;
    mActive = false;
    mInit = false;
    mSourceManager = nullptr;
    mErrorReporter = nullptr;
}

Compiler::~Compiler()
{
    delete mSourceManager;
    delete mErrorReporter;
}

void Compiler::compileFromString(std::string inputData, std::string sourceLocation)
{
    if (!mInit)
        setup();
    auto input = mSourceManager->initMemoryBuffer(sourceLocation, inputData);
    compileSource(input);
}

bool Compiler::compileFromFile(std::string filepath)
{
    if (!mInit)
        setup();

    auto input = mSourceManager->initFileBuffer(filepath);
    if (!input)
        return false;
    compileSource(input);
    return true;
}

void Compiler::setup()
{
    if (mInit)
        return;
    mSourceManager = createSourceManager();
    mErrorReporter = createErrorReporter();
    mInit = true;
}

SourceManager *Compiler::createSourceManager()
{
    return new SourceManager{};
}

ErrorReporter *Compiler::createErrorReporter()
{
    return new ErrorReporter{this};
}

} // namespace hydro::compiler
