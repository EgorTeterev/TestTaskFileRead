#pragma once
#include "FindCollisionTransformer.h"
#include "KhoaraSortTransformer.h"
#include "ReverseSortedCollisionTransformer.h"
#include "ReverseTransformer.h"


enum class TransformClasses
{
	FindCollision,
	Sort,
	Reverse,
	ReverseSortedCollisionTransformer
};

template<typename Container>
class ArrayTransformFactory
{
public:
	static ArrayTransformer<Container>* Create(const TransformClasses TransformName)
	{
		switch (TransformName)
		{
		case(TransformClasses::FindCollision):
			{
				return new FindCollisionTransformer<Container>();
				break;
			}
			case(TransformClasses::Sort):
			{
				return new KhoaraSortTransformer<Container>();
				break;
			}
			case(TransformClasses::Reverse):
			{
				return new ReverseTransformer<Container>();
					break;
			}
			case(TransformClasses::ReverseSortedCollisionTransformer):
			{
				return new ReverseSortedCollisionTransformer<Container>();
				break;
			}

		}
	}
};

