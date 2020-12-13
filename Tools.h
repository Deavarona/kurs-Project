#ifndef TOOLS_H
#define TOOLS_H
#include "Calendar.h"
#include <Windows.h>
#include "File.h"
#include "Constants.h"
#include <conio.h>

void setSettings(); //��������� ���������
int inputIntegerNumber(); //���� ������ �����
bool isActionConfirmed(std::string message); //������������� ��������

//---------- � � � � ----------

void showMainMenuInterface(); //��������� �������� ����
void mainMenu(); //������� ����
void menuShowingTasks(); //���� ������ ����� �� �������
void showMenuShowingTasksInterface(); //��������� ���� ������ �����
void menuEditionTasks(); //���� ������������� �����
void showEditionMenuInterface(); //��������� ���� �������������� �����

#endif
