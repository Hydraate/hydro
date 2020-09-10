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

#ifndef __h3o_engine_UnaryExpression__
#define __h3o_engine_UnaryExpression__

#include "Expression.hpp"

namespace hydro::engine
{

class UnaryExpression : public Expression
{
protected:
    /**
     * Creates a UnaryExpression object with some subject expression.
     * @param expression The subject of the unary expression.
     */
    UnaryExpression(Expression *expression);
    
public:
    /**
     * Destroys the UnaryExpression object.
     */
    virtual ~UnaryExpression();
    
    /**
     * Gets the expression.
     * @return Returns the expression that is the subject of the unary expression.
     */
    Expression *getExpression() const { return mExpression; }
    
private:
    /**
     * The subject expression.
     */
    Expression *mExpression;
};

} // namespace hydro::engine

#endif /* __h3o_engine_UnaryExpression__ */
