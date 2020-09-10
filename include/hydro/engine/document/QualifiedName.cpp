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

namespace hydro::engine
{

QualifiedName::QualifiedName(Name *qualifier, compiler::Token token, SimpleName *name) : Name{ token }
{
    mQualifier = qualifier;
    mName = name;
}

QualifiedName::~QualifiedName()
{
    delete mQualifier;
    delete mName;
}

std::string QualifiedName::getValue() const
{
    return mQualifier->getValue() + '.' + mName->getValue();
}

} // namespace hydro::engine
