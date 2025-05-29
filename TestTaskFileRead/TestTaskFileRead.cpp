#include "PCH.h"


//enter your file path
#define ARRAYFILEPATH "ReadArrays.txt"

// "зчитувати масиви з файлу".
void ReadLineFromFile(std::ifstream& Stream, std::string& String, const int LinesToIgnore = 0)
{
	Stream.seekg(0);

	if (!Stream.is_open())
	{
		std::cerr << " Could not open file\r";
		return;
	}

	if (LinesToIgnore<0)
	{
		std::cerr << " cant ignore negative value of lines\r";
		return;
	}


	//skip file lines, that are already processed
	if (LinesToIgnore > 0)
	{
		for (int i = 0; i < LinesToIgnore; ++i)
		{
			Stream.ignore(LONG_MAX, '\n');
		}
	}

	std::getline(Stream, String, '\n');

	return;
}

//"друкувати вміст масивів" (не зрозумів,з файлу,чи з std::vector)
void LogLineFromFile(std::ifstream& Stream, int ArrayLine = 1)
{
	std::string Line;
	if (ArrayLine > 0)
	{
		ReadLineFromFile(Stream, Line, ArrayLine - 1);
	} 
}

template <typename Container, typename Elem>
void FilterStringToContainer( Container& Con, std::string& String)
{
	FormatString(String);

	//extract int,push to vector and delete all until next space
	size_t Deleate = 0;
	while ((Deleate = String.find(" ")) != std::string::npos)
	{
		int IntFromString = std::stoi(String, 0);
		Con.push_back(IntFromString);

		String.erase(0, Deleate+1);
	}
}

//"щоб вони могли приймати будь-які типи даних, що ітеруються з STL"
template <typename Container,typename Elem>
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
		ReadLineFromFile(Stream, TempString, ArrayLine - 1);
	}
	else
	{
		ReadLineFromFile(Stream, TempString, ArrayLine);
	}

	FilterStringToContainer<Container,Elem>(Con, TempString);

}



int main()
{
/* 
"Буде дано текстовий файл, де в рядок буде задекларовано три масиви цілих чисел.
Кожен масив описується окремим рядком числа розділені або пробілом, або комою,
або двома символами одночасно".

File ReadArrays.txt:
12516,1,16, 15,610,32,161,491, 204 161 2151 1964 129 4939 921 5312 312 11 521\r\n - first arr line
12,125,7,1234,634,1 124, 74 23 11 22 1 1 24, 21\r\n                       - second arr line
105,270,15 21 3165, 32,15 215 22 22(EOF)                                  - third arr line

*/

	std::ifstream Stream(ARRAYFILEPATH);
	std::vector<int> First,Second,Third;

	FitFileLineToContainer<std::vector<int>,int>(Stream, First);
	ConsoleVector(&First);


}






















//template <typename ArrType, typename ...Arrays>
//void FitFileLinesToVectors(std::ifstream& Stream,size_t FirstLinesToRead,std::vector<ArrType>& Array,Arrays& ...OtherArraysToFit)
//{
//	if (!Stream.is_open())
//	{
//		std::cerr << " Could not open file\n";
//		return;
//	}
//
//	std::string TempString;
//	ReadLineFromFile(Stream, TempString, FirstLinesToRead);
//
//
//	FitFileLinesToVectors(Stream, FirstLinesToRead, OtherArraysToFit...);
//}
