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

#include "Scope.hpp"

namespace hydro::compiler
{
Scope::Scope() : m_parent{nullptr} {}

Scope::Scope(std::string name) : m_name{name}, m_parent{nullptr} {}

Scope::Scope(Scope *enclosingScope) : m_parent{enclosingScope} {}

Scope::Scope(std::string name, Scope *enclosingScope) : m_name{name}, m_parent{enclosingScope} {}

Scope::~Scope() {}

} // namespace hydro::compiler
