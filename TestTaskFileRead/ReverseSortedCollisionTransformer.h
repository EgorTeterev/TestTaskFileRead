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

	virtual void Transform(Container& Con) override {};
	virtual void Transform(Container& Con1, Container& Con2) override {};
	virtual void Transform(Container& Con1, Container& Con2, Container& Con3) override {};

	virtual Container* TransformWithResult(const Container& Con) override { return nullptr; };

	virtual Container* TransformWithResult(const Container& Con1, const Container& Con2) override { return nullptr; };

	virtual Container* TransformWithResult(const Container& Con1, const Container& Con2, const Container& Con3) override { return nullptr; };

private:
	ReverseSortedCollisionTransformer() = default;
	//void ReverseArray(Container& ConToReverse);
	//void SortArray(Container& ConToSort);
	//Container* FindCollision(Container& Con1, Container& Con2);
};

