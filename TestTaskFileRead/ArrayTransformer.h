#pragma once
#include "PCH.h"

template<typename Elem>
class ArrayTransformer 
{
public:
	virtual void Transform(std::vector<Elem>& ArrayToTransform) = 0;
};