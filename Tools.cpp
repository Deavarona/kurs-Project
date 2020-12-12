#include "Tools.h"

int inputIntegerNumber()
{
	int number;
	while (1)
	{
		std::cin >> number;
		if (std::cin.get() == '\n')
		{
			return number;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Некорректный ввод!" << std::endl;
			std::cout << "Повторный ввод: ";
		}
	}
}

void setSettings()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (!isFileExist(DATABASE_FILE_NAME))
	{
		createFile(DATABASE_FILE_NAME);
	}
}