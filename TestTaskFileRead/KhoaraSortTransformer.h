#pragma once
#include "ArrayTransformer.h"

template<typename Container>
class KoaraSortTransformer : public ArrayTransformer<Container>
{
public:

//"сортувати масиви без допомоги вбудованих функцій". Вбудованних функцій? Своя функція Swap :)
	virtual void TransformOne(Container& Con) override
	{
		KhoaraSort(Con, 0, Con.size() - 1);
	};
	virtual void TransformTwo(Container& Con1, Container& Con2) override
	{
		KhoaraSort(Con1, 0, Con1.size() - 1);
		KhoaraSort(Con2, 0, Con2.size() - 1);
	};
	virtual void TransformThree(Container& Con1, Container& Con2, Container& Con3) override
	{
		KhoaraSort(Con1, 0, Con1.size() - 1);
		KhoaraSort(Con2, 0, Con2.size() - 1);
		KhoaraSort(Con3, 0, Con3.size() - 1);
	};
private:
	KoaraSortTransformer() = default;
	void KhoaraSort(Container& Con, size_t left, size_t right);
};



template <typename Container>
void HoarSortTransformer<Container>::KhoaraSort(Container& Con, size_t left, size_t right)
{
	auto pivot = Con[left];
	int l = left;
	int r = right;

	while (left < right)
	{
		while ((Con[right] >= pivot) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			Con[left] = Con[right];
			left++;
		}
		while ((Con[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			Con[right] = Con[left];
			right--;
		}
	}

	Con[left] = pivot;
	pivot = left;
	left = l;
	right = r;

	if (left < pivot)
	{
		KhoaraSort(Con, left, pivot - 1);
	}
	if (right > pivot)
	{
		KhoaraSort(Con, pivot + 1, right);
	}

}