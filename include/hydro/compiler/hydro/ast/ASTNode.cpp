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

#include "ASTNode.hpp"

namespace hydro::compiler
{
ASTNode::ASTNode(AST *owner)
{
    m_owner = owner;
}

ASTNode::~ASTNode() {}

int32_t ASTNode::getStartPosition() const
{
    return -1;
}

int32_t ASTNode::getEndPosition() const
{
    return -1;
}

} // namespace hydro::compiler
