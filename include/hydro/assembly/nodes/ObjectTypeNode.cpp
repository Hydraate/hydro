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

#include "ObjectTypeNode.hpp"

namespace hydro
{

ObjectTypeNode::ObjectTypeNode() {}


ObjectTypeNode::~ObjectTypeNode() {}

void ObjectTypeNode::build(Chunk *chunk)
{
    
}

VM_Type *ObjectTypeNode::make()
{
    return new VM_ObjectType{};
}

} // namespace hydro
