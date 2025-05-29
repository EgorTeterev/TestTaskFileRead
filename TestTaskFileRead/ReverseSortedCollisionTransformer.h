#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"
#include "ReverseTransformer.h"
#include "KhoaraSortTransformer.h"
#include "FindCollisionTransformer.h"

template<typename Container>
class ReverseSortedCollisionTransformer : public ArrayTransformer<Container>
{
	template<typename T>
	friend class ArrayTransformFactory;
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
	ReverseSortedCollisionTransformer() = default;
	void ReverseArray(Container& ConToReverse);
	void SortArray(Container& ConToSort);
	Container* FindCollision(Container& Con1, Container& Con2);
};

template<typename Container>
inline void ReverseSortedCollisionTransformer<Container>::SortArray(Container& ConToSort)
{
}

template<typename Container>
inline Container* ReverseSortedCollisionTransformer<Container>::FindCollision(Container& Con1, Container& Con2)
{
	return nullptr;
}
