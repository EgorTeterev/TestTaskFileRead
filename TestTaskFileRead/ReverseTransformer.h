#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"

template<typename Container>
class ReverseTransformer : public ArrayTransformer<Container>
{
public:
	virtual void Transform(Container& Array) override
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