#include <iostream>
#include <cmath>
#include "../my_lib.h"
#include "lab_05.h"

namespace lab_05
{
	void task_1();
	void task_2();
	void task_3();
	void task_4();
	void task_5();

	//Пользовательский ввод
	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(a) Задание 1 \n"
			"(b) Задание 2\n"
			"(c) Задание 3\n"
			"(d) Задание 4\n"
			"(e) Задание 5\n" << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	// Пользовательское меню
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
			case 'e': task_5(); break;
			case '0': std::cout << "Выход из программы" << std::endl; break;
			default: std::cout << "Неправильный ввод, попробуйте снова" << std::endl;
			}
		}
	}

	// Функция нахождения факториала
	int factorial(int a)
	{
		int f = 1;
		do
		{
			f *= a;
			a -= 1;
		} while (a != 0);
		return f;
	}

	// Вывод факториал числа
	void task_1()
	{
		std::cout << "Задание 1: Вывод факториал числа" << std::endl;
		std::cout << "Введите число, для нахождения факториала: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "Факториал числа: " << a << " равен " << factorial(a) << std::endl;
		std::cout << std::endl;
	}

	// Алгоритм Евклида
	int nod(int a, int b)
	{
		while (a % b != 0)
		{
			int c = b;
			b = a % b;
			a = c;
		}
		return b;
	}

	// НОД двух чисел
	void task_2()
	{
		std::cout << "Задание 2: Поиск наибольшего общего делителя 2х чисел" << std::endl;
		std::cout << "Введите первое число: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "Введите второе число: " << std::endl;
		std::cout << "b = ";
		int b = n_ReadInt(INT_MAX);
		if (b == INT_MAX)
			return;
		std::cout << "НОД числа " << a << " и " << "числа " << b << " равен: " << nod(a, b) << std::endl;
		std::cout << std::endl;
	}

	// Проверка простое ли число
	void prime_number(int a)
	{
		int cnt = 0;
		for (int i = 2; i < sqrt(a); ++i)
		{
			if (a % i == 0)
			{
				++cnt;
			}
		}
		if (cnt == 0 && a != 1)
			std::cout << "Введенное число a = " << a << " является простым" << std::endl;
		else
			std::cout << "Введенное число a = " << a << " не является простым" << std::endl;
	}

	// Является ли введенное число простым 
	void task_3()
	{
		std::cout << "Задание 3: Является ли введенное число простым?" << std::endl;
		std::cout << "Введите число: " << std::endl;
		std::cout << "N = ";
		double a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		prime_number(a);
		std::cout << std::endl;
	}

	// Проверка на палиндром
	void palindrom(std::string a)
	{
		int j = 0;
		for (int i = a.size(); --i > (a.size() / 2); )
		{
			if (a[j] != a[i])
			{
				std::cout << "Введенная строка " << a << " не является палиндромом" << std::endl;
				break;
			}
			++j;
		}
		if (j == a.size() / 2)
			std::cout << "Введенная строка " << a << " является палиндромом" << std::endl;
	}

	// Является ли введенная строка палиндромом
	void task_4()
	{
		std::string s;
		std::cout << "Задание 4: Является ли введенная строка палиндромом?" << std::endl;
		std::cout << "Введите строку: ";
		std::cin >> s;
		palindrom(s);
	}

	// Числа Фибоначчи
	int fibonacci_number(int a)
	{
		if (a == 1)
			return 1;
		else if (a == 0)
			return 0;
		else
			return fibonacci_number(a - 2) + fibonacci_number(a - 1);
	}

	// Вычисление чисел Фибоначчи
	void task_5()
	{
		std::cout << "Задание 5: Вывод чисел Фибоначчи" << std::endl;
		std::cout << "Введите крайнее число: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "Числа Фибоначчи: ";
		int i = 0;
		while (i != a + 1)
		{
			std::cout << fibonacci_number(i) << "\t";
			++i;
		}
		std::cout << std::endl;
	}
} // namespace