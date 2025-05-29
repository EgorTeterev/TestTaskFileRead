#pragma once
#include "ArrayTransformer.h"

template<typename Elem>
class HoarSortTransformer : public ArrayTransformer<Elem>
{
public:
//"сортувати масиви без допомоги вбудованих функцій". Вбудованних функцій? Своя функція Swap
	virtual void Transform(std::vector<Elem>& Array) override
	{
		KhoaraSort(Array, 0, Array.size() - 1);
	};

private:
	HoarSortTransformer() = default;
	void KhoaraSort(std::vector<Elem>& VectorToSort, size_t left, size_t right);
};



template <typename Elem>
void HoarSortTransformer<Elem>::KhoaraSort(std::vector<Elem>& VectorToSort, size_t left, size_t right)
{
	Elem pivot = VectorToSort[left];
	int l = left;
	int r = right;

	while (left < right)
	{
		while ((VectorToSort[right] >= pivot) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			VectorToSort[left] = VectorToSort[right];
			left++;
		}
		while ((VectorToSort[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			VectorToSort[right] = VectorToSort[left];
			right--;
		}
	}

	VectorToSort[left] = pivot;
	pivot = left;
	left = l;
	right = r;

	if (left < pivot)
	{
		KhoaraSort(VectorToSort, left, pivot - 1);
	}
	if (right > pivot)
	{
		KhoaraSort(VectorToSort, pivot + 1, right);
	}

}