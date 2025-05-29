#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"


template<typename Container>
class ReverseTransformer : public ArrayTransformer<Container>
{
	template<typename T>
	friend class ArrayTransformFactory;
public:

	virtual void TransformOne(Container& Con) override
	{
		ReverseArray(Con);
	};

	virtual void TransformTwo(Container& Con1, Container& Con2) override
	{
		ReverseArray(Con1);
		ReverseArray(Con2);
	};

	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) override
	{
		ReverseArray(Con1);
		ReverseArray(Con2);
		ReverseArray(Con3);
	};


	virtual Container* TransformOneWithResult(const Container& Con) override { return nullptr; };

	virtual Container* TransformTwoWithResult(const Container& Con1, const Container& Con2) override { return nullptr; };

	virtual Container* TransformThreeWithResult(const Container& Con1, const Container& Con2, const Container& Con3) override { return nullptr; };

private:
	ReverseTransformer() = default;
	void ReverseArray(Container& VectorToSort);
};

template<typename Container>
void ReverseTransformer<Container>::ReverseArray(Container& Con)
{
	std::reverse(Con.begin(), Con.end());
}


