#pragma once
#include <vector>
#include <iostream>
#include "Utils.h"
#include "Read.h"

struct FileReader;

template<typename Elem>
void ConsoleCon(const std::vector<Elem>* Con)
{
	if (Con != nullptr)
	{
		auto end = Con->end();
		for (auto it = Con->begin(); it != end; it++)
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

template <typename Container, typename Elem>
void FilterStringToContainer(Container& Con, std::string& String)
{
	FormatString(String);

	//extract int,push to vector and delete all until next space
	size_t Deleate = 0;
	while ((Deleate = String.find(" ")) != std::string::npos)
	{
		int IntFromString = std::stoi(String, 0);
		Con.push_back(IntFromString);

		String.erase(0, Deleate + 1);
	}
}

//"щоб вони могли приймати будь-які типи даних, що ітеруються з STL"
template <typename Container, typename Elem>
void FitFileLineToContainer(std::ifstream& Stream, Container& Con, const int ArrayLine = 1)
{
	if (!Stream.is_open())
	{
		std::cerr << " Could not open file\n";
		return;
	}
	std::string TempString;

	if (ArrayLine > 0)
	{
		FileReader::ReadLineFromFile(Stream, TempString, ArrayLine - 1);
	}
	else
	{
		FileReader::ReadLineFromFile(Stream, TempString, ArrayLine);
	}

	FilterStringToContainer<Container, Elem>(Con, TempString);

}