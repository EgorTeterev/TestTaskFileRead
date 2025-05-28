#include <vector>
#include <iostream>

template<typename Elem>
void ConsoleVector(std::vector<Elem>* vector)
{
	if (vector != nullptr)
	{
		auto end = vector->end();
		for (auto it = vector->begin(); it != end; it++)
		{
			std::cout << *it << " ";
		}
	}
	std::cout << "\n";
}

template<typename Elem>
void Swap(Elem& Elem1, Elem Elem2)
{
	Elem temp = Elem1;
	Elem1 = Elem2;
	Elem2 = temp;
}

