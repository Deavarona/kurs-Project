#ifndef FILE_H
#define FILE_H
#include "Tools.h"
#include <fstream>
#include "Note.h"
#include <string>
#include "Calendar.h"

void checkFileExisting(std::string name_of_file); 
int defineNumberOfLinesAtFile(std::string name_of_file);

void writeToFoleNoteWithoutDeadline(std::string name_of_file, Note& note);
void showFileContent(std::string name_of_file);
void writeToFileNoteWithDeadline(std::string name_of_file, Calendar& note);

#endif