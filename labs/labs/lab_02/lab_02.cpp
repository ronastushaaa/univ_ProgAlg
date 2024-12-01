#include <windows.h> // Библиотека для кодировки
#include <iostream>
#include "../my_lib.h"
#include "lab_02.h"

namespace lab_02
{
	void task_1();
	void task_2();
	void task_3();
	void task_4();

	// Вывод меню и получение выбора пользователя
	char select_task()
	{
		char a = '-'; 
		std::cout << "Выберите задание, которое вас интересует (a, b, c, d): \n"
			" (a) task_1 \n"
			" (b) task_2 \n"
			" (c) task_3 \n"
			" (d) task_4 " << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	// Вывод основного меню
	void menu()
	{
		char a = '-';
		while (a != '0')
		{
			a = select_task();
			switch (a)
			{
				case 'a': task_1(); break;
				case 'b': task_2(); break;
				case 'c': task_3(); break;
				case 'd': task_4(); break;
				case '0': std::cout << "Выход из программы." << std::endl; break;
				default: std::cout << "Неправльный ввод" << std::endl;
			}
		}
	}

	// Проверка на целое число (возвращает успешность преобразования)
	bool to_integer(std::string s, int* num = NULL)
	{
		if (s.size() == 0)
			return false;
		char* pEnd;
		int res = strtol(s.c_str(), &pEnd, 10);
		if (NULL != num)
		  (*num) = res;
		return (strlen(pEnd) == 0);
	}


	// Задание на проверку чётности
	void task_1()
	{
		std::string sa;

		std::cout << "Задание 1: Проверка числа на чётность." << std::endl;
		std::cout << "Введите число, которое хотите проверить: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_integer(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (a % 2 == 0)
		{
			std::cout << "Число a = " << a << " чётное!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Число a = " << a << " нечётное!" << std::endl;
			std::cout << std::endl;
		}
	}

	// Проверка на вискосный год
	void task_2()
	{
		std::string sa;

		std::cout << "Задание 2: Високосный ли год?" << std::endl;
		std::cout << "Введите год, который хотите проверить:" << std::endl;
		std::cout << "год - ";
		std::cin >> sa;
		int year;
		if (!to_integer(sa, &year))
		{
			std::cout << "Ошибка: 'year' должно быть числом!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if ((year % 4 == 0 && !(year % 100 == 0)) || (year % 100 == 0 && year % 400 == 0))
		{
			std::cout << year << " год является вискосным!" << std::endl;
			std::cout << std::endl;
		}
		else if (year % 100 == 0)
		{
			std::cout << year << " год не является вискосным!" << std::endl;
			std::cout << std::endl;
		}
	}

	// Проверка на число (возвращает успешность преобразования)
	bool to_double(std::string s, double* num)
	{
		if (s.size() == 0)
			return false;
		char* pEnd;
		(*num) = strtold(s.c_str(), &pEnd);
		return (strlen(pEnd) == 0);

	}

	// Поиск максимального числа из трёх
	void task_3()
	{
		std::string sa, sb, sc;

		std::cout << "Задание 3: Поиск максимального числа из трёх" << std::endl;
		std::cout << "Введите три числа a, b и c:" << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом!" << std::endl;
			std::cout << std::endl;
			return;
		}
		std::cout << "b = ";
		std::cin >> sb;
		double b;
		if (!to_double(sb, &b))
		{
			std::cout << "Ошибка: 'b' должно быть числом!" << std::endl;
			std::cout << std::endl;
			return;
		}
		std::cout << "c = ";
		std::cin >> sc;
		double c;
		if (!to_double(sc, &c))
		{
			std::cout << "Ошибка: 'c' должно быть числом!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (a >= b && a >= c)
		{
			std::cout << "Число " << a << " самое максимальное!";
			std::cout << std::endl;
		}
		else if (b >= a && b >= c)
		{
			std::cout << "Число " << b << " самое максимальное!";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Число " << c << " самое максимальное!";
			std::cout << std::endl;
		}
	}

	// Является ли введенная буква гласной или согласной
	void task_4()
	{
		std::string vowels = "AaEeIiOoUuYyАаУуОоИиЭэЫыЯяЮюЕеЁё";


		//int ord_a = (int)'a';
		//int ord_z = (int)'z';

		//IsCharAlpha

		std::string letter = "";
		std::cout << "Задание 4: Является ли введенная буква гласной или согласной" << std::endl;
		std::cout << "Введите букву на проверку" << std::endl;
		std::cout << "Буква - ";
		std::cin >> letter;
		if (to_integer(letter))
		{
			std::cout << "Ошибка: должна быть введена буква!" << std::endl;
			std::cout << std::endl;
			return;
		}
		else if (letter.size() != 1)
		{
			std::cout << "Ошибка: должна быть введена буква!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (vowels.find(letter) < vowels.size())
		{
			std::cout << vowels.find(letter);
			std::cout << "Буква '" << letter << "' является гласной!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Буква '" << letter << "' является согласной!" << std::endl;
			std::cout << std::endl;
		}
	} 
}