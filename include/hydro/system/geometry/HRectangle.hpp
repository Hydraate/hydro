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

#ifndef __h3o_HRectangle__
#define __h3o_HRectangle__

#include "../HObject.hpp"

namespace hydro
{

typedef object_ptr<class HRectangle> hrectangle;

class HRectangle : public HObject
{
public:
    virtual ~HRectangle();
    double x() const;
    void x(double value);
    double y() const;
    void y(double value);
    double width() const;
    void width(double value);
    double height() const;
    void height(double value);
    hrectangle clone();
 
protected:
    HRectangle(HvmEnv *env, HClass *RectangleClass);

private:
    double m_x, m_y, m_width, m_height;
    
    void construct(double x, double y, double width, double height);
    double h3o_get_x();
    void h3o_set_x(double value);
    double h3o_get_y();
    void h3o_set_y(double value);
    double h3o_get_width();
    void h3o_set_width(double value);
    double h3o_get_height();
    void h3o_set_height(double value);
    hrectangle h3o_clone();
    
    template <typename X>
    friend class NativeClassAllocator;
    friend class HvmEnv;
};

} // namespace hydro

#endif /* __h3o_HRectangle__ */
