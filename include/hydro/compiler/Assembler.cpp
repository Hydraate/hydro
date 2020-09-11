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

#include "Assembler.hpp"

namespace hydro::compiler
{
Assembler::Assembler(Lexer *lexer) : Parser{lexer}
{
}

Assembler::~Assembler()
{
}

void Assembler::program(SourceBuffer *buffer)
{
    parse(buffer);
}

void Assembler::registerOpcode(std::string name, uint8_t opcode)
{
    mDefinitions.push_back(new BytecodeDefinition{name, opcode});
}

uint8_t Assembler::readOpcode()
{
    std::string name = tokenVal();

    for (BytecodeDefinition *def : mDefinitions)
        if (def->name == name)
            return def->opcode; // success!

    // fail
    abrupt();
    return 0;
}

} // namespace hydro::compiler
