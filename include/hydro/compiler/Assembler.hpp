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

#ifndef __h3o_Assembler__
#define __h3o_Assembler__

#include <list>

#include "Assembler.hpp"
#include "BytecodeDefinition.hpp"
#include "Parser.hpp"
#include "SourceBuffer.hpp"

namespace hydro::compiler
{
/**
     * The Assembler class is an abstract parser for assembling bytecodes.
     */
class Assembler : protected Parser
{
protected:
    /**
     * Assembler constructor
     */
    Assembler(Lexer *lexer);

public:
    /**
     *
     */
    virtual ~Assembler();

    /**
     *
     */
    void program(SourceBuffer *buffer);

protected:
    /**
     *
     */
    std::list<BytecodeDefinition *> mDefinitions;

    /**
     *
     */
    void registerOpcode(std::string name, uint8_t opcode);

    /**
     *
     */
    uint8_t readOpcode();
};

} // namespace hydro::compiler

#endif /* __h3o_AssemblerParser__ */
