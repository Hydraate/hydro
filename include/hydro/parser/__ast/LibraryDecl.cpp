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

#include "LibraryDecl.hpp"

namespace hydro
{

LibraryDecl::LibraryDecl(Token *token, LibrarySymbol *symbol, Stmt *body) : ScopedDecl(token, symbol, body) {}

LibraryDecl::~LibraryDecl() {}

} // namespace hydro
