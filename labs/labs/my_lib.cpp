#include <iostream>
#include <vector>
#include "my_lib.h"

// Является ли символ пробелом
bool n_IsSpace(char ch)
{
	switch (ch)
	{
		case ' ':   // space
		case '\f':  // form feed
		case '\n':  // newline or linefeed (0x0A)
		case '\r':  // carriage return     (0x0D)
		case '\t':  // horizontal tab
		case '\v':  // vertical tab
			return true;
		default:
			return false;
	} // switch
}

// Удаляет пробельные символы с начала и с конца строки
std::string n_Trim(std::string str)
{
	//"  qwe123 " -> "qwe123"
	std::size_t cnt = 0;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (!n_IsSpace(str[i])) break;
		++cnt;
	}
	str.erase(0, cnt);
	cnt = 0;
	for (std::size_t i = str.length(); --i > 0; )
	{
		if (!n_IsSpace(str[i])) break;
		++cnt;
	}
	str.erase(str.length() - cnt, cnt);
	return str;
}

// Выкусывает подстроку из строки по разделителю
std::string n_Token(std::string& str, std::string sep, bool trim)
{
	//"qwe 123 fff" -> return "qwe", s = "123 fff"

	std::size_t idx = str.find(sep);
	std::string res = str.substr(0, idx);
	str = str.erase(0, idx + sep.length());
	if (trim)
	{
		res = n_Trim(res);
		str = n_Trim(str);
	}
	return res;
}


// Разбивает строку на подстроки по разделителю
void n_Split(std::string str, std::vector<std::string>& v, std::string sep, bool trim)
{
	//"qwe 123 fff" -> "qwe", "123"
	while (str.length() != 0)
	{
		v.push_back(n_Token(str, sep, trim));
	}
}


// Проверка на число (возвращает успешность преобразования)
bool to_double(std::string s, double* num)
{
	if (s.size() == 0)
		return false;
	char* pEnd;
	double res = strtold(s.c_str(), &pEnd);
	if (num != NULL)
		(*num) = res;
	return (strlen(pEnd) == 0);
}

// Проверка на целое число (возвращает успешность преобразования)
bool to_number(std::string s, int* num)
{
	if (s.size() == 0)
		return false;
	char* pEnd;
	int res = strtol(s.c_str(), &pEnd, 10);
	if (num != NULL)
		(*num) = res;
	return (strlen(pEnd) == 0);
}

// Чтение данных из stdin
int n_ReadInt(int def)
{
	std::string s;
	std::cin >> s;
	int num;
	if (!to_number(s, &num))
	{
		std::cout << "Ошибка: должно быть введено число!" << "\n";
		return def;
	}
	return num;
}

// Чтение данных из stdin
double n_ReadDouble(double def)
{
	std::string s;
	std::cin >> s;
	double num;
	if (!to_double(s, &num))
	{
		std::cout << "Ошибка: должно быть введено число!" << "\n";
		return def;
	}
	return num;
}