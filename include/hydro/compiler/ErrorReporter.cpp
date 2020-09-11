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

#include "ErrorReporter.hpp"

namespace hydro::compiler
{
ErrorReporter::ErrorReporter(Compiler *compiler) : mCompiler{compiler}, mNumErrors{0}, mNumWarnings{0} {}

ErrorReporter::~ErrorReporter()
{
    for (compilation_error *err : mErrors)
        delete err;
}

void ErrorReporter::reportError(std::string errorText, SourcePosition pos)
{
    mErrors.push_back(new compilation_error{
        errorText,
        pos,
        error_status::error});
    mNumErrors++;
}

void ErrorReporter::reportError(std::string errorText, Token erroneousToken)
{
    reportError(
        errorText,
        erroneousToken.pos());
    mNumWarnings++;
}

void ErrorReporter::reportWarning(std::string errorText, SourcePosition pos)
{
    mErrors.push_back(new compilation_error{
        errorText,
        pos,
        error_status::warning});
}

void ErrorReporter::reportWarning(std::string errorText, Token erroneousToken)
{
    reportWarning(
        errorText,
        erroneousToken.pos());
}

uint32_t ErrorReporter::numErrors(const SourceID &source) const
{
    uint32_t n = 0;
    for (auto err : mErrors)
        if (err->pos.source() == source && err->status == error_status::error)
            n++;
    return n;
}

uint32_t ErrorReporter::numWarnings(const SourceID &source) const
{
    uint32_t n = 0;
    for (auto err : mErrors)
        if (err->pos.source() == source && err->status == error_status::error)
            n++;
    return n;
}

uint32_t ErrorReporter::numErrorsAndWarnings(const SourceID &source) const
{
    uint32_t n = 0;
    for (auto err : mErrors)
        if (err->pos.source())
            n++;
    return n;
}


int32_t ErrorReporter::errorIndexAtPosition(const SourcePosition &pos) const
{
    for (int32_t i = 0; i < mErrors.size(); i++)
        if (mErrors[i]->pos == pos)
            return i;

    // fail
    return -1;
}

std::string ErrorReporter::errorText(const SourcePosition &pos) const
{
    int32_t index = errorIndexAtPosition(pos);

    if (index >= 0)
        return mErrors[index]->errorText;

    // fail
    return "";
}

} // namespace hydro::compiler
