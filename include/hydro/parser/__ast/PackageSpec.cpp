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

#include "PackageSpec.hpp"

namespace hydro
{

PackageSpec::PackageSpec(lex_token pkgToken) : Ast{pkgToken} {}

PackageSpec::~PackageSpec() {}

} // namespace hydro
