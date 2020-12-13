#ifndef TOOLS_H
#define TOOLS_H
#include "Calendar.h"
#include <Windows.h>
#include "File.h"
#include "Constants.h"
#include <conio.h>

void setSettings(); //Начальные настройки
int inputIntegerNumber(); //Ввод целого числа
bool isActionConfirmed(std::string message); //Подтверждение действия

//---------- М Е Н Ю ----------

void showMainMenuInterface(); //Интерфейс главного меню
void mainMenu(); //Главное меню
void menuShowingTasks(); //Меню вывода задач на консоль
void showMenuShowingTasksInterface(); //Интерфейс меню вывода задач
void menuEditionTasks(); //Меню редактировния задач
void showEditionMenuInterface(); //Интерфейс меню редактирования задач

#endif
