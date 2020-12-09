#include <iostream>
#include <Windows.h>
#include "Note.h"
#include "Calendar.h"
#include "File.h"
#include "Tools.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Note mynote;
	writeToFoleNoteWithoutDeadline(MAIN_FILE_NAME, mynote);
	showFileContent(MAIN_FILE_NAME);
}