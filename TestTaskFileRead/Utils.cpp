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

}