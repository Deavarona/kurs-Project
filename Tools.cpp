#include "Tools.h"

int inputNumber()
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