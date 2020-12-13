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
bool isActionConfirmed(std::string message)
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t" << message << std::endl;
	std::cout << "\tЛюбой символ: подтвердить" << std::endl;
	std::cout << "\t0 - отменить" << std::endl;
	std::cout << LINE_MENU << std::endl;
	if (_getch() == '0')
	{
		std::cout << "Данные будут потеряны" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

//---------- М Е Н Ю ----------

void showMainMenuInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. Добавить задачу" << std::endl;
	std::cout << "\t2. Показать задачи" << std::endl;
	std::cout << "\t3. Редактировать задачу" << std::endl;
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t4. Узнать задачи на сегодня" << std::endl;
	std::cout << "\t5. Просмотреть заметки" << std::endl;
	std::cout << "\t6. Открыть календарь" << std::endl;
	std::cout << "\t0 - Выход" << std::endl;
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

//---------- Д О Б А В Л Е Н И Е ----------


//---------- В Ы В О Д ----------

void showMenuShowingTasksInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. Показать все задачи." << std::endl;
	std::cout << "\t2. Показать все задачи с дедлайном." << std::endl;
	std::cout << "\t3. Показать все невыполненные задачи." << std::endl;
	std::cout << "\t4. Показать все задачи за выбранный ГОД." << std::endl;
	std::cout << "\t5. Показать все задачи за выбранный МЕСЯЦ." << std::endl;
	std::cout << "\t6. Показать все задачи за выбранный ДЕНЬ." << std::endl;
	std::cout << "\t7. Сортировать по приоритету." << std::endl;
	std::cout << "\t0 - Вернуться назад." << std::endl;
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

//---------- Р Е Д А К Т И Р О В А Н И Е ----------

void showEditionMenuInterface()
{
	std::cout << LINE_MENU << std::endl;
	std::cout << "\t1. Редактировать имя заметки." << std::endl;
	std::cout << "\t2. Редактировать описание заметки." << std::endl;
	std::cout << "\t3. Редактировать дедлайн." << std::endl;
	std::cout << "\t4. Редактировать статус." << std::endl;
	std::cout << "\t5. Редактировать приоритет." << std::endl;
	std::cout << "\t6. Удалить заметку." << std::endl;
	std::cout << "\t0 - Вернуться назад." << std::endl;
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
		case '6': notes.at(note_number).deleteNote(notes, note_number, number_of_notes); std::cout << "Задача удалена." << std::endl;
		case '0': 
		{
			if (isActionConfirmed(MESSAGE_SAVE))
			{
				note.rewriteFile(DATABASE_FILE_NAME, notes, number_of_notes);
				std::cout << "Успешно сохранено." << std::endl;
			}
			else
			{
				std::cout << "Данные не были изменены." << std::endl;
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