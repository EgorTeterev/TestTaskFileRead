#pragma once
#include "ArrayTransformer.h"
#include "ArrayTransformerFactory.h"
#include "PCH.h"
#include "Templates.h"


template<typename Container>
class FindCollisionTransformer : public ArrayTransformer<Container>
{
	template<typename T>
	friend class ArrayTransformFactory;
public:

	virtual void Transform(Container& Con) {};
	virtual void Transform(Container& Con1, Container& Con2) {};
	virtual void Transform(Container& Con1, Container& Con2, Container& Con3) {};

	virtual Container* TransformWithResult(Container& Con) override
	{
		return nullptr;
	};

	virtual Container* TransformWithResult(Container& Con1,Container& Con2) override
	{
		Container* Result = new Container();

		if (Result != nullptr)
		{
			FindCollision(Result, Con1, Con2);
		}

		return Result;
	};

	virtual Container* TransformWithResult(Container& Con1,Container& Con2, Container& Con3) override
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

	void FindCollision(Container* Result, Container& Con1, Container& Con2);
	void FindCollision(Container* Result, Container& Con1, Container& Con2, Container& Con3);
};

template<typename Container>
void FindCollisionTransformer<Container>::FindCollision(Container* Result, Container& Con1, Container& Con2)
{
	if (Con1.size() > 0 && Con2.size() > 0)
	{
		std::sort(Con1.begin(), Con1.end());
		std::sort(Con2.begin(), Con2.end());
		std::set_intersection(Con1.begin(), Con1.end(), Con2.begin(), Con2.end(), back_inserter(*Result));

		auto it = std::unique(Result->begin(), Result->end());
		Result->resize(std::distance(Result->begin(), it));
	}
}

template<typename Container>
void FindCollisionTransformer<Container>::FindCollision(Container* Result, Container& Con1, Container& Con2, Container& Con3)
{
	Container TempCon = Container();
	if (Con1.size() > 0 && Con2.size() > 0)
	{
		std::sort(Con1.begin(), Con1.end());
		std::sort(Con2.begin(), Con2.end());

		std::set_intersection(Con1.begin(), Con1.end(), Con2.begin(), Con2.end(), back_inserter(TempCon));
	}
	
	if (Con3.size() > 0)
	{
		std::sort(Con3.begin(), Con3.end());
		std::set_intersection(TempCon.begin(), TempCon.end(), Con3.begin(), Con3.end(), back_inserter(*Result));
	}

	auto it = std::unique(Result->begin(), Result->end());
	Result->resize(std::distance(Result->begin(), it));
}