#include <iostream>
#include "Constants.h"
#include "Tools.h"
#include "File.h"
#include "Notebook.h"
#include "ThisMoment.h"
#include "Calendar.h"

int main()
{
	setSettings();
	Calendar note;
	int number_of_notes = defineNumberOfNotesInFile(DATABASE_FILE_NAME);
	std::vector <Calendar> notes(number_of_notes);
	note.readAllNotesFromFile(DATABASE_FILE_NAME, notes, number_of_notes);
	note.showAllNotes(notes, number_of_notes);
}