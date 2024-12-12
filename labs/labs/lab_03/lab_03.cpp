#include <iostream>
#include <cmath>
#include "../my_lib.h"
#include "lab_03.h"

namespace lab_03
{

	void task_1();
	void task_2();
	void task_3();
	void task_4();
	void task_5();
	void task_6();
	void task_7();
	void task_8();

	//Пользовательский ввод
	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(a) Задание 1 (for)\n"
			"(b) Задание 1 (while)\n"
			"(c) Задание 2 (for)\n"
			"(d) Задание 2 (while)\n"
			"(e) Задание 3 (for)\n"
			"(f) Задание 3 (while)\n"
			"(g) Задание 4 (for)\n"
			"(h) Задание 4 (while)" << std::endl;
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
			case 'f': task_6(); break;
			case 'g': task_7(); break;
			case 'h': task_8(); break;
			case '0': std::cout << "Выход из программы" << std::endl; break;
			default: std::cout << "Неправильный ввод, попробуйте снова" << std::endl;
			}
		}
	}

	// Вывод таблицы умножения (for)
	void task_1()
	{
		std::string sa;
		std::cout << "Задание 1: Вывод таблицы умножения для конкретного числа" << std::endl;
		std::cout << "Введите число, для построения фрагмента таблицы: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом!" << "\n";
			return;
		}
		std::cout << "Фрагмент таблицы умножения:" << std::endl;
		for (int i = 1; i < 11; ++i)
		{
			std::cout << a * i << "\t";
		}
		std::cout << std::endl << "\n";
	}

	// Вывод таблицы умножения (while)
	void task_2()
	{
		std::string sa;

		std::cout << "Задание 1: Вывод таблицы умножения для конкретного числа" << std::endl;
		std::cout << "Введите число, для построения фрагмента таблицы: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом!" << "\n";
			return;
		}
		int i = 1;
		std::cout << "Фрагмент таблицы умножения:" << std::endl;
		while (i < 11)
		{
			std::cout << i * a << "\t";
			++i;
		}
		std::cout << std::endl << "\n";
	}

	// Сумма чисел от 1 до N (for)
	void task_3()
	{
		std::string sa;

		std::cout << "Задание 2: Сумма чисел от 1 до N" << std::endl;
		std::cout << "Введите число: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "Ошибка: 'N' должно быть числом!" << "\n";
			return;
		}
		int summ = 0;
		for (int i = 1; i < a + 1; ++i)
		{
			summ += i;
		}
		std::cout << "Сумма составляет " << summ << std::endl << "\n";
	}

	// Сумма чисел от 1 до N (while)
	void task_4()
	{
		std::string sa;

		std::cout << "Задание 2: Сумма чисел от 1 до N" << std::endl;
		std::cout << "Введите число: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "Ошибка: 'N' должно быть числом!" << "\n";
			return;
		}
		int summ = 0, i = 1;
		while (i < a + 1)
		{
			summ += i;
			++i;
		}
		std::cout << "Сумма составляет " << summ << std::endl << "\n";
	}

	// Является ли введенное число простым (for)
	void task_5()
	{
		std::string sa;

		std::cout << "Задание 3: Является ли введенное число простым?" << std::endl;
		std::cout << "Введите число, которое хотите проверить: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом!" << "\n";
			return;
		}
		int cnt = 0;
		for (int i = 2; i < sqrt(a); ++i)
		{
			if (a % i == 0)
			{
				++cnt;
			}
		}
		if (cnt == 0 && a != 1)
		{
			std::cout << "Число " << a << " является простым!" << std::endl << "\n";
		}
		else
		{
			std::cout << "Число " << a << " не является простым!" << std::endl << "\n";
		}
	}

	// Является ли введенное число простым (while)
	void task_6()
	{
		std::string sa;

		std::cout << "Задание 3: Является ли введенное число простым?" << std::endl;
		std::cout << "Введите число, которое хотите проверить: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "Ошибка: 'a' должно быть числом!" << "\n";
			return;
		}
		int cnt = 0, i = 2;
		while (i < sqrt(a))
		{
			if (a % i == 0)
			{
				++cnt;
			}
			++i;
		}
		if (cnt == 0 && a != 1)
		{
			std::cout << "Число " << a << " является простым!" << std::endl << "\n";
		}
		else
		{
			std::cout << "Число " << a << " не является простым!" << std::endl << "\n";
		}
	}

	// Факториал числа (for)
	void task_7()
	{
		std::cout << "Задание 4: Факториал числа" << std::endl;
		std::cout << "Введите число: " << std::endl;
		std::cout << "N = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
		{
			return;
		}
		int factorial = 1;
		for (int i = 1; i < a + 1; ++i)
		{
			factorial *= i;
		}
		std::cout << "Факториал числа " << a << " составляет " << factorial << std::endl << "\n";
	}

	// Факториал числа (while)
	void task_8()
	{
		std::string sa;

		std::cout << "Задание 4: Факториал числа" << std::endl;
		std::cout << "Введите число: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "Ошибка: 'N' должно быть числом!" << "\n";
			return;
		}
		int factorial = 1, i = 1;
		while (i < a + 1)
		{
			factorial *= i;
			++i;
		}
		std::cout << "Факториал числа " << a << " составляет " << factorial << std::endl << "\n";
	}

} // namespace