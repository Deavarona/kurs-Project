#ifndef FILE_H
#define FILE_H
#include "Tools.h"
#include <fstream>
#include "Note.h"
#include <string>
#include "Calendar.h"
#include <vector>

void checkFileExisting(std::string name_of_file); 
int defineNumberOfLinesAtFile(std::string name_of_file);

void writeToFile(std::string name_of_file, Note& note);
void showFileContent(std::string name_of_file);
void writeToFile(std::string name_of_file, Calendar& note);

void readFromFile(std::string name_of_file, std::vector<Note>& note, int number_of_notes);
void readFromFile(std::string name_of_file, std::vector<Calendar>&note, int number_of_notes);

#endif