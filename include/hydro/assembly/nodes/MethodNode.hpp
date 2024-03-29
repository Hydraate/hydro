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

#ifndef __h3o_MethodNode__
#define __h3o_MethodNode__

#include "FuncNode.hpp"
#include "../../vm/VM_Method.hpp"

namespace hydro
{

class MethodNode : public FuncNode
{
private:
	VM_Method *_method;

public:
	MethodNode(VM_Method *method);
	virtual ~MethodNode();
	virtual void build(Chunk *chunk);
	VM_Method *method() const { return _method; }
};

} // namespace hydro

#endif /* __h3o_MethodNode__ */
