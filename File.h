#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>

bool isFileExist(std::string name_of_file);
void createFile(std::string name_of_file);
int defineNumberOfNotesInFile(std::string name_of_file);
void showFileContent(std::string name_of_file);

#endif