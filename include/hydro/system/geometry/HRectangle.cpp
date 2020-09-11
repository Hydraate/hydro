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

#include "HRectangle.hpp"
#include "../../vm/HvmEnv.hpp"

namespace hydro
{

HRectangle::HRectangle(HvmEnv *env, HClass *RectangleClass) : HObject{env, RectangleClass} {}

HRectangle::~HRectangle() {}

void HRectangle::construct(double x, double y, double width, double height)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
}

double HRectangle::x() const
{
    return mEnv->get()->property(this, "x");
}

void HRectangle::x(double value)
{
    mEnv->set()->property(this, "x", value);
}

double HRectangle::y() const
{
    return mEnv->get()->property(this, "y");
}

void HRectangle::y(double value)
{
    mEnv->set()->property(this, "y", value);
}

double HRectangle::width() const
{
    return mEnv->get()->property(this, "width");
}

void HRectangle::width(double value)
{
    mEnv->set()->property(this, "width", value);
}

double HRectangle::height() const
{
    return mEnv->get()->property(this, "height");
}

void HRectangle::height(double value)
{
    mEnv->set()->property(this, "height", value);
}

hrectangle HRectangle::clone()
{
    return mEnv->call()->property(this, "clone");
}

double HRectangle::h3o_get_x() { return m_x; }

void HRectangle::h3o_set_x(double value) { m_x = value; }

double HRectangle::h3o_get_y() { return m_y; }

void HRectangle::h3o_set_y(double value) { m_y = value; }

double HRectangle::h3o_get_width() { return m_width; }

void HRectangle::h3o_set_width(double value) { m_width = value; }

double HRectangle::h3o_get_height() { return m_height; }

void HRectangle::h3o_set_height(double value) { m_height = value; }

hrectangle HRectangle::h3o_clone()
{
    return mEnv->make()->object(mClass, m_x, m_y, m_width, m_height).tryCast<HRectangle>();
}

} // namespace hydro
