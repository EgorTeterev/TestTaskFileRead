#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"
#include "Templates.h"

template<typename Container>
class FindCollisionTransformer : public ArrayTransformer<Container>
{
	template<typename T>
	friend class ArrayTransformFactory;
public:

	virtual void TransformOne(Container& Con) {};
	virtual void TransformTwo(Container& Con1, Container& Con2) {};
	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) {};

	virtual Container* TransformOneWithResult(const Container& Con) override
	{
		return nullptr;
	};

	virtual Container* TransformTwoWithResult(const Container& Con1, const  Container& Con2) override
	{
		Container* Result = new Container();

		if (Result != nullptr)
		{
			FindCollision(Result, Con1, Con2);
		}

		return Result;
	};

	//first container will get the result
	virtual Container* TransformThreeWithResult(const Container& Con1, const Container& Con2, const Container& Con3) override
	{
		Container* Result = new Container();

		if (Result != nullptr)
		{
			FindCollision(Result, Con1, Con2,Con3);
		}

		return Result;
	};

private:
	FindCollisionTransformer() = default;
	void FindCollision(Container* Result,const Container& Con1, const Container& Con2);
	void FindCollision(Container* Result, const Container& Con1, const Container& Con2, const Container& Con3);

};

template<typename Container>
void FindCollisionTransformer<Container>::FindCollision(Container* Result,const Container& Con1, const Container& Con2)
{

}

template<typename Container>
void FindCollisionTransformer<Container>::FindCollision(Container* Result, const Container& Con1, const Container& Con2, const Container& Con3)
{

}
