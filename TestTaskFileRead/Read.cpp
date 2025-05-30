#include "Read.h"

void FileReader::ReadLineFromFile(std::ifstream& Stream, std::string& String, const int LinesToIgnore)
{
	Stream.seekg(0);

	if (!Stream.is_open())
	{
		std::cerr << " Could not open file\r";
		return;
	}

	if (LinesToIgnore < 0)
	{
		std::cerr << " cant ignore negative value of lines\r";
		return;
	}

	if (LinesToIgnore > 0)
	{
		for (int i = 0; i < LinesToIgnore; ++i)
		{
			Stream.ignore(LONG_MAX, '\n');
		}
	}

	std::getline(Stream, String, '\n');

	//should close?

	return;
}

void FileReader::LogLineFromFile(std::ifstream& Stream, int ArrayLine)
{
	std::string Line;
	if (ArrayLine > 0)
	{
		FileReader::ReadLineFromFile(Stream, Line, ArrayLine - 1);
	}
	
	ConsoleSTDString(&Line);
}
