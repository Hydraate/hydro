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

#include "Node.hpp"

namespace hydro::engine
{
Node::Node()
{
    mDocument = nullptr;
}

Node::Node(compiler::Token token)
{
    mToken = token;
    mDocument = nullptr;
}

Node::~Node()
{
}

} // namespace hydro::engine
