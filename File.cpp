#include "File.h"

bool isFileExist(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	if (!file.is_open())
	{
		return false;
	}
	file.close();
	return true;
}
void createFile(std::string name_of_file)
{
	std::ofstream new_file(name_of_file);
	new_file.close();
}
int defineNumberOfNotesInFile(std::string name_of_file)
{
	std::ifstream file(name_of_file, std::ios::in);
	std::string temp;
	int number_of_lines = 0;
	while (std::getline(file, temp, '\n'))
	{
		number_of_lines++;
	}
	file.close();
	return number_of_lines;
}
void showFileContent(std::string name_of_file)
{
	std::string temp;
	try
	{
		std::ifstream file(name_of_file, std::ios::in);
		if (!file.is_open())
		{
			throw 1;
		}
		while (!file.eof())
		{
			std::getline(file, temp, '\n');
			std::cout << temp << std::endl;
		}
		file.close();
	}
	catch (const int file_error)
	{
		if (file_error == 1)
		{
			std::cout << "Файл не может быть открыт. Повторите попытку." << std::endl;
			if (!isFileExist(name_of_file))
			{
				createFile(name_of_file);
			}
		}
	}
}