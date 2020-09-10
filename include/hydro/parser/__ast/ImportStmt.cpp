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

#include "ImportStmt.hpp"

namespace hydro
{

ImportStmt::ImportStmt(lex_token token, Name *name) : Stmt{token}, _name{name} {}

ImportStmt::~ImportStmt() {}

} // namespace hydro
