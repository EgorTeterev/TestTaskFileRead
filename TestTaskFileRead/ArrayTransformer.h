#pragma once
#include "PCH.h"

template<typename Container>
class ArrayTransformer 
{
public:
	virtual void TransformOne(Container& Con) = 0;
	virtual void TransformTwo(Container& Con1, Container& Con2) = 0;
	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) = 0;

	virtual Container TransformOneWithResult(Container& Con) = 0;
	virtual Container TransformTwoWithResult(Container& Con1, Container& Con2) = 0;
	virtual Container TransformThreeWithResult(Container& Con1, Container& Con2, Container& Con3) = 0;

};
