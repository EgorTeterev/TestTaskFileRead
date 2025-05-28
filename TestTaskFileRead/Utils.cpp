#include <string>
#include <iostream>

void ConsoleSTDString(std::string* str)
{
	if (str != nullptr)
	{
		auto end = str->end();
		for (auto it = str->begin(); it != end; it++)
		{
			std::cout << *it;
		}
		std::cout << "\n";
	}

}
