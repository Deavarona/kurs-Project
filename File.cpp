#include "File.h"

void checkFileExisting(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	if (!file.is_open())
	{
		std::ofstream new_file(name_of_file);
		new_file.close();
	}
	file.close();
}

int defineNumberOfLinesAtFile(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	
	std::string temp;
	int number_of_lines = 0;
	while (std::getline(file, temp, '\n'))
	{
		number_of_lines++;
	}
	return number_of_lines;
}