#pragma once
#include "PCH.h"

template<typename Container>
class ArrayTransformer 
{
public:
	virtual void Transform(Container& Con) = 0;
	virtual void Transform(Container& Con1, Container& Con2) = 0;
	virtual void Transform(Container& Con1, Container& Con2, Container& Con3) = 0;

	virtual Container* TransformWithResult(const Container& Con) = 0;
	virtual Container* TransformWithResult(const Container& Con1, const Container& Con2) = 0;
	virtual Container* TransformWithResult(const Container& Con1, const Container& Con2, const Container& Con3) = 0;

};
