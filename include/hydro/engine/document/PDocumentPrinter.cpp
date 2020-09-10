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

#include "PDocumentPrinter.hpp"

namespace hydro::engine
{

PDocumentPrinter::PDocumentPrinter(std::ostream &out) : mOut{ out }
{
}

PDocumentPrinter::~PDocumentPrinter()
{
}

} // namespace hydro::engine
