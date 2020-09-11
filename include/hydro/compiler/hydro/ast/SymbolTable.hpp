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

#ifndef __h3o_internal_SymbolTable__
#define __h3o_internal_SymbolTable__

#include "Scope.hpp"

namespace hydro::compiler
{
class SymbolTable : public Scope
{
public:
    SymbolTable();
    virtual ~SymbolTable();
};

} // namespace hydro::compiler

#endif /* __h3o_internal_SymbolTable__ */
