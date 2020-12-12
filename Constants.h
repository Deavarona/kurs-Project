#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <vector>

const int DEFAULT_VALUE = -1; //Присваивается данное значение, если оно не было определено
const std::string DEFAULT_VALUE_STRING = "UNKNOWN"; //Присваивается данное значение, если оно не было определено
//----------
const char SPECIAL_SYMBOL = '\''; //Специальный символ ' (используется при работе с файлом (запись/считывание))
//----------
const std::string DATABASE_FILE_NAME = "Organaiser_Database.txt"; //Имя основного файла с данными задач

#endif