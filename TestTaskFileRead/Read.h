#pragma once
#include "PCH.h"

struct FileReader
{
	static void ReadLineFromFile(std::ifstream& Stream, std::string& String, const int LinesToIgnore = 0);
	static void LogLineFromFile(std::ifstream& Stream, int ArrayLine = 1);

};