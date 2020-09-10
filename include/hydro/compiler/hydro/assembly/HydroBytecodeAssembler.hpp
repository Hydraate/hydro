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

#ifndef __h3o_HydroBytecodeAssembler__
#define __h3o_HydroBytecodeAssembler__

#include "../../../vm/Chunk.hpp"
#include "../../../vm/opcodes.hpp"
#include "../../Assembler.hpp"

namespace hydro::compiler
{
class HydroBytecodeAssembler final : public Assembler
{
public:
    HydroBytecodeAssembler(Compiler *compiler);

protected:
    virtual void parseFromCurrentToken() override;
};

} // namespace hydro::compiler

#endif /* __h3o_HydroBytecodeAssembler__ */
