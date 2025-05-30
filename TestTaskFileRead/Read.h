#pragma once
#include "PCH.h"
#include "Utils.h"

struct FileReader
{
	// "зчитувати масиви з файлу".
	static void ReadLineFromFile(std::ifstream& Stream, std::string& String, const int LinesToIgnore = 0);

	//"друкувати вміст масивів" (не зрозумів,з файлу,чи з std::vector)
	static void LogLineFromFile(std::ifstream& Stream, int ArrayLine = 1);
};