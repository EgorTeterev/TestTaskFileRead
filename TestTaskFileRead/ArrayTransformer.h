#pragma once
#include "PCH.h"

template<typename Container>
class ArrayTransformer 
{
public:
	virtual void Transform(Container& ArrayToTransform) = 0;
};