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

#include "any.hpp"

namespace hydro
{

any::any() : mContent{nullptr} {}

any::any(any &&x) : mContent{std::move(x.mContent)} {}

any::any(any &x)
{
	if (x.mContent)
		mContent = x.mContent->clone();
}

any::any(const any &x)
{
	if (x.mContent)
		mContent = x.mContent->clone();
}

any::~any() {}

any &any::operator=(any &&rhs)
{
	mContent = std::move(rhs.mContent);
	return (*this);
}

any &any::operator=(const any &rhs)
{
	mContent = std::move(any(rhs).mContent);
	return (*this);
}

bool any::empty() const { return mContent == nullptr; }

const std::type_info &any::type() const { return mContent ? mContent->type() : typeid(void); }

void any::clear() { mContent.reset(nullptr); }

} // namespace hydro
