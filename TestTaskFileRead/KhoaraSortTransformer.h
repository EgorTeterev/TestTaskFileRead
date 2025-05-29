#pragma once
#include "ArrayTransformer.h"

template<typename Container>
class HoarSortTransformer : public ArrayTransformer<Container>
{
public:
	HoarSortTransformer() = default;
//"сортувати масиви без допомоги вбудованих функцій". Вбудованних функцій? Своя функція Swap :)
	virtual void Transform(Container& Con) override
	{
		KhoaraSort(Con, 0, Con.size() - 1);
	};

private:

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