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
	virtual Container* TransformOneWithResult(const Container& Con) override
	{
		return nullptr;
	};

	//first container will get the result
	virtual Container* TransformTwoWithResult(const Container& Con1, const  Container& Con2) override
	{
		return FindCollision(Con1, Con2);
	};

	//first container will get the result
	virtual Container* TransformThreeWithResult(const Container& Con1, const Container& Con2, const Container& Con3) override
	{
		return nullptr;
	};

private:
	FindCollisionTransformer() = default;
	Container* FindCollision(const Container& Con1, const Container& Con2);
};

template<typename Container>
Container* FindCollisionTransformer<Container>::FindCollision(const Container& Con1, const Container& Con2)
{
	if (Con1.size() > 0 && Con2.size() > 0)
	{
		Container* Result = new Container();

		auto Con1End = Con1.end();
		auto Con2End = Con2.end();

		for (auto Con1Begin = Con1.begin(); Con1Begin != Con1End; Con1Begin++)
		{

			for (auto Con2Begin = Con2.begin(); Con2Begin != Con2End; Con2Begin++)
			{
				if (*Con1Begin == *Con2Begin)
				{
					//std::cout << "Pushed: " << *Con1Begin<<'\n';
					Result->push_back(*Con1Begin);
				}
			}

		}
		return Result;
	}

	return nullptr;
}
