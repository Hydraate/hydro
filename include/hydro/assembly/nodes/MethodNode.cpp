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

#include "MethodNode.hpp"

namespace hydro
{

MethodNode::MethodNode(VM_Method *method) : FuncNode{method}, _method{method} {}

MethodNode::~MethodNode() {}

void MethodNode::build(Chunk *chunk)
{
	FuncNode::build(chunk);
}

} // namespace hydro
