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
			std::cout << "������������ ����!" << std::endl;
			std::cout << "��������� ����: ";
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
bool isActionConfirmed(std::string message)
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t" << message << std::endl;
	std::cout << "\t����� ������: �����������" << std::endl;
	std::cout << "\t0 - ��������" << std::endl;
	std::cout << LINE_MENU << std::endl;
	if (_getch() == '0')
	{
		std::cout << "������ ����� ��������" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

//---------- � � � � ----------

void showMainMenuInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. �������� ������" << std::endl;
	std::cout << "\t2. �������� ������" << std::endl;
	std::cout << "\t3. ������������� ������" << std::endl;
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t4. ������ ������ �� �������" << std::endl;
	std::cout << "\t5. ����������� �������" << std::endl;
	std::cout << "\t6. ������� ���������" << std::endl;
	std::cout << "\t0 - �����" << std::endl;
	std::cout << LINE_MENU << std::endl;
}
void mainMenu()
{
	Calendar calendar;
	calendar.showCalendarCurrentMonth();
	calendar.whatTheDayToday();
	showMainMenuInterface();
	bool should_continue = true;
	while (should_continue)
	{
		switch (_getch())
		{
		case '1': system("cls"); addNote(); break;
		case '2': system("cls"); menuShowingTasks(); break;
		case '3': system("cls"); menuEditionTasks(); break;
		case '4': system("cls"); calendar.todayTasks(); break;
		case '5': system("cls"); calendar.showNotesWithoutDeadline(); break;
		case '6': system("cls"); calendar.createCalendarYear(); break;
		case '0': if (isActionConfirmed(MESSAGE_EXIT)) should_continue = false; else system("cls"); break;
		default:continue;
		}
		if (should_continue)
		{
			calendar.showCalendarCurrentMonth();
			calendar.whatTheDayToday();
			showMainMenuInterface();
		}
	}
}

//---------- � � � � � � � � � � ----------


//---------- � � � � � ----------

void showMenuShowingTasksInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. �������� ��� ������." << std::endl;
	std::cout << "\t2. �������� ��� ������ � ���������." << std::endl;
	std::cout << "\t3. �������� ��� ������������� ������." << std::endl;
	std::cout << "\t4. �������� ��� ������ �� ��������� ���." << std::endl;
	std::cout << "\t5. �������� ��� ������ �� ��������� �����." << std::endl;
	std::cout << "\t6. �������� ��� ������ �� ��������� ����." << std::endl;
	std::cout << "\t7. ����������� �� ����������." << std::endl;
	std::cout << "\t0 - ��������� �����." << std::endl;
	std::cout << LINE_MENU << std::endl;
}
void menuShowingTasks()
{
	Calendar note;
	int number_of_notes = defineNumberOfNotesInFile(DATABASE_FILE_NAME);
	std::vector <Calendar> notes(number_of_notes);
	note.readAllNotesFromFile(DATABASE_FILE_NAME, notes, number_of_notes);

	showMenuShowingTasksInterface();
	bool should_continue = true;
	while (should_continue)
	{
		switch (_getch())
		{
		case '1': system("cls"); note.showAllNotes(notes, number_of_notes); break;
		case '2': system("cls"); note.showNotesWithDeadline(notes, number_of_notes); break;
		case '3': system("cls"); note.showUnfulfilledNotes(notes, number_of_notes); break;
		case '4': system("cls"); note.showNotesThisYear(notes, number_of_notes); break;
		case '5': system("cls"); note.showNotesThisMonth(notes, number_of_notes); break;
		case '6': system("cls"); note.showNotesThisDay(notes, number_of_notes); break;
		case '7': system("cls"); note.sortPriority(notes, number_of_notes); break;
		case '0': system("cls"); should_continue = false; break;
		default: continue;
		}
		if (should_continue)
		{
			showMenuShowingTasksInterface();
		}
	}
}

//---------- � � � � � � � � � � � � � � ----------

void showEditionMenuInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. ������������� ��� �������." << std::endl;
	std::cout << "\t2. ������������� �������� �������." << std::endl;
	std::cout << "\t3. ������������� �������." << std::endl;
	std::cout << "\t4. ������������� ������." << std::endl;
	std::cout << "\t5. ������������� ���������." << std::endl;
	std::cout << "\t6. ������� �������." << std::endl;
	std::cout << "\t0 - ��������� �����." << std::endl;
	std::cout << LINE_MENU << std::endl;
}
void menuEditionTasks()
{
	Calendar note;
	int number_of_notes = defineNumberOfNotesInFile(DATABASE_FILE_NAME);
	std::vector<Calendar> notes(number_of_notes);
	note.readAllNotesFromFile(DATABASE_FILE_NAME, notes, number_of_notes);

	int note_number = note.chooseTheNoteNumber(notes, number_of_notes);

	system("cls");
	notes.at(note_number).showNote(notes.at(note_number));
	showEditionMenuInterface();
	bool should_continue = true;

	while (should_continue)
	{
		switch (_getch())
		{
		case '1': notes.at(note_number).editNoteName(notes.at(note_number)); system("cls"); break;
		case '2': notes.at(note_number).editNoteContent(notes.at(note_number)); system("cls"); break;
		case '3': notes.at(note_number).editNoteDeadline(notes.at(note_number)); system("cls"); break;
		case '4': notes.at(note_number).editNoteStatus(notes.at(note_number)); system("cls"); break;
		case '5': notes.at(note_number).editNotePriority(notes.at(note_number)); system("cls"); break;
		case '6': notes.at(note_number).deleteNote(notes, note_number, number_of_notes); std::cout << "������ �������." << std::endl;
		case '0': 
		{
			if (isActionConfirmed(MESSAGE_SAVE))
			{
				note.rewriteFile(DATABASE_FILE_NAME, notes, number_of_notes);
				std::cout << "������� ���������." << std::endl;
			}
			else
			{
				std::cout << "������ �� ���� ��������." << std::endl;
			}
			Sleep(1000);
			system("cls");
			should_continue = false;
		}
		default: continue;
		}
		if (should_continue)
		{
			notes.at(note_number).showNote(notes.at(note_number));
			showEditionMenuInterface();
		}
	}
}