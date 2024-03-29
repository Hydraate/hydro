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

#ifndef __h3o_FuncNode__
#define __h3o_FuncNode__

#include "InstrGroupNode.hpp"
#include "../../vm/VM_Func.hpp"

namespace hydro
{

class FuncArgNode : public BlockNode
{
protected:
	FuncArg *_arg;
	InstrGroupNode *_defaultVal;

public:
	FuncArgNode(FuncArg *arg, InstrGroupNode *defaultVal = nullptr);
	virtual ~FuncArgNode();
	virtual void build(Chunk *nhunk) override;
	FuncArg *arg() const { return _arg; }
};

class FuncNode : public BlockNode
{
protected:
	VM_Func *_func;
	std::vector<FuncArgNode *> _args;
    std::vector<class TryNode *> _errorHandlers;
    
public:
	FuncNode(VM_Func *func);
	virtual ~FuncNode();
	void appendArg(FuncArgNode *arg);
    void appendTry(TryNode *tryCatch);
	virtual void build(Chunk *chunk) override;
	VM_Func *func() const { return _func; }
};

} // namespace hydro

#endif /* __h3o_FuncNode__ */
