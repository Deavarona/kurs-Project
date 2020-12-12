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

void showMainMenuInterface();
void mainMenu();
void addNote();
void menuOfShowingTasks();
void showMenuOfShowingTasksInterface();
void editNote();
void showEditionMenu();

#endif
