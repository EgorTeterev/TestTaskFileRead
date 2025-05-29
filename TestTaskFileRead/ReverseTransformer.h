#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"

template<typename Elem>
class ReverseTransformer : public ArrayTransformer<Elem>
{
public:
	virtual void Transform(std::vector<Elem>& Array) override
	{

	};
private:
	ReverseTransformer() = default;
	void ReverseArray(std::vector<Elem>& VectorToSort);
};
template<typename Elem>
void ReverseTransformer<Elem>::ReverseArray(std::vector<Elem>& VectorToSort)
{

}