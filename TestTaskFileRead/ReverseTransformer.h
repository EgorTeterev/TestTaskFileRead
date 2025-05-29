#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"

template<typename Container>
class ReverseTransformer : public ArrayTransformer<Container>
{
public:
	virtual void TransformOne(Container& Con) override
	{

	};

	virtual void TransformTwo(Container& Con1, Container& Con2) override
	{

	};

	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) override
	{

	};
private:
	ReverseTransformer() = default;
	void ReverseArray(Container& VectorToSort);
};
template<typename Container>
void ReverseTransformer<Container>::ReverseArray(Container& VectorToSort)
{

}