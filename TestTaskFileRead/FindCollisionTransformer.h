#pragma once

#include "ArrayTransformer.h"

template<typename Container>
class FindCollisionTransformer : public ArrayTransformer<Container>
{
public:

	//you will get nothing
	virtual void TransformOneWithResult(Container& Con) override
	{

	};

	//first container will get the result
	virtual void TransformTwoWithResult(Container& ContainerTo, Container& Con2) override
	{

	};

	//first container will get the result
	virtual void TransformThreeWithResult(Container& Container, Container& Con2, Container& Con3) override
	{

	};
private:
	FindCollisionTransformer() = default;
	void KhoaraSort(Container& Con, size_t left, size_t right);
};
