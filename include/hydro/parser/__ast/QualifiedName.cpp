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

#include "QualifiedName.hpp"


namespace hydro
{

QualifiedName::QualifiedName(Name *qualifier, SimpleName *name) :  Name{name->token()}, _qualifier{qualifier}, _name{name} {}

QualifiedName::~QualifiedName() {}

} // namespace hydro
