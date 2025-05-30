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

//Очікує Потік, Контейнер, Номер строки для чтіння (1 по дефолту)
//Читає строку з файлу, запихує у std::string, фільтруе строку та запихує в контейнер
template <typename Container, typename Elem>
void FitFileLineToContainer(std::ifstream& Stream, Container& Con, const int ArrayLine = 1)
{
	if (!Stream.is_open())
	{
		std::cerr << " Could not open file\n";
		return;
	}
	std::string TempString;

//Якщо строка для чтіння більше за 1, треба проігнорувати декілька строк
	if (ArrayLine > 0)
	{
		//Якщо треба читати строку n - треба проігнорувати строки n-1, до неї
		FileReader::ReadLineFromFile(Stream, TempString, ArrayLine - 1);
	}
	else
	{
		//при від'ємному - читає перший рядок, при 0 - теж
		FileReader::ReadLineFromFile(Stream, TempString, 0);
	}

//фільтрує отриману строку (видаля коми, та зайві пробіли), та запихує в контейнер
	FilterStringToContainer<Container, Elem>(Con, TempString);

}