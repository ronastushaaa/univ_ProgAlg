#pragma once
#include <vector>

// Функции для работы со строками
bool        n_IsSpace(char ch);

std::string n_Trim (std::string  str);
std::string n_Token(std::string &str, std::string sep, bool trim = true);
void        n_Split(std::string  str, std::string sep, std::vector<std::string> &v, bool trim = true);


// Проверка на число (возвращает успешность преобразования)
bool to_double(std::string s, double* num = NULL);

// Проверка на целое число (возвращает успешность преобразования)
bool to_number(std::string s, int* num = NULL);

// Чтение данных из stdin
int    n_ReadInt(int def);
double n_ReadDouble(double def);