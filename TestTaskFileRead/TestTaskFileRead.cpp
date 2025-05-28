#include "PCH.h"


//enter your file path
#define ARRAYFILEPATH "ReadArrays.txt"


// "зчитувати масиви з файлу".
void ReadLineFromFile(std::ifstream& Stream, std::string& String, int LinesToIgnore = 0)
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

//"друкувати вміст масивів"
void LogLineFromFile(std::ifstream& Stream, int ArrayLine = 1)
{
	std::string Line;
	if (ArrayLine > 0)
	{
		ReadLineFromFile(Stream, Line, ArrayLine - 1);
	} 


}

void FormatString(std::string& str)
{
	auto end = str.end();
	for (auto it = str.begin(); it != end; it++)
	{
		if (*it == ',')
		{
			*it = ' ';
		}
	}

	//find and deleate double spaces
	size_t Deleate;
	while ((Deleate = str.find("  ")) != std::string::npos)
	{
		str.replace(str.find("  "), 2, " ");
	}

	//if first two elements were spaces - delete unnecessary space, in [0]
	if (str[0] == ' ')
	{
		str.erase(0, 1);
	}
	if (str[str.size()] != ' ')
	{
		str.push_back(' ');
	}

	//ConsoleSTDString(&str);
}

template <typename Elem>
void FilterStringToArray(std::string& String, std::vector<Elem>& Vector)
{

	FormatString(String);

	//extract int,push to vector and delete all until next space
	size_t Deleate = 0;
	while ((Deleate = String.find(" ")) != std::string::npos)
	{
		int IntFromString = std::stoi(String, 0);
		Vector.push_back(IntFromString);

		String.erase(0, Deleate+1);
	}
}

template <typename Elem>
void FitFileLineToVector(std::ifstream& Stream,  std::vector<Elem>& Array, int ArrayLine = 1)
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

	FilterStringToArray<Elem>(TempString, Array);

}



int main()
{
/* 
"Буде дано текстовий файл, де в рядок буде задекларовано три масиви цілих чисел.
Кожен масив описується окремим рядком числа розділені або пробілом, або комою,
або двома символами одночасно".

File ReadArrays.txt:
1, 16,610,32,161,491, 204 161\r\n  - first arr line
 12,125,7,1234,634,1 124, 74\r\n   - second arr line
105,270,15 21 3165, 32,15(EOF)     - third arr line

*/

	std::ifstream Stream(ARRAYFILEPATH);
	std::vector<int> First,Second,Third; // File lines to vectors

	FitFileLineToVector(Stream, First);
	FitFileLineToVector(Stream, Second,2);
	FitFileLineToVector(Stream, Third,3);

	ConsoleVector<int>(&First);
	ConsoleVector<int>(&Second);
	ConsoleVector<int>(&Third);


	

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
