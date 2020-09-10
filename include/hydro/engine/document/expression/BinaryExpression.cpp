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

#include "BinaryExpression.hpp"

namespace hydro::engine
{

BinaryExpression::BinaryExpression(Expression *lhs, Expression *rhs) : Expression{}
{
    mLhs = lhs;
    mRhs = rhs;
}

BinaryExpression::BinaryExpression(Expression *lhs, compiler::Token token, Expression *rhs) : Expression{token}
{
    mLhs = lhs;
    mRhs = rhs;
}

BinaryExpression::~BinaryExpression()
{
}

} // namespace hydro::engine
