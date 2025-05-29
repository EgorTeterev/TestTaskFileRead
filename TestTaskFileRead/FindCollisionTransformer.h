#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"

template<typename Container>
class FindCollisionTransformer : public ArrayTransformer<Container>
{
	template<typename T>
	friend class ArrayTransformFactory;
public:


	virtual void TransformOne(Container& Con) {};
	virtual void TransformTwo(Container& Con1, Container& Con2) {};
	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) {};

	//you will get nothing
	virtual Container* TransformOneWithResult(Container& Con) override
	{

	};

	//first container will get the result
	virtual Container* TransformTwoWithResult(Container& Con1, Container& Con2) override
	{

	};

	//first container will get the result
	virtual Container* TransformThreeWithResult(Container& Con1, Container& Con2, Container& Con3) override
	{

	};
private:
	FindCollisionTransformer() = default;

};
