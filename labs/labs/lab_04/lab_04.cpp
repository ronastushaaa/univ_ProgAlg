#include <iostream>
#include <windows.h>
#include <fstream>
#include "../my_lib.h"
#include "lab_04.h"

namespace lab_04
{

	void task_1();
	void task_2();
	void task_3();
	void task_4();

	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(a) Задание 1 \n"
			"(b) Задание 2 \n"
			"(c) Задание 3 \n"
			"(d) Задание 4" << std::endl;
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
			case'a': task_1(); break;
			case'b': task_2(); break;
			case'c': task_3(); break;
			case'd': task_4(); break;
			case'0': std::cout << "Выход из программы" << std::endl; break;
			default: std::cout << "Неправильный ввод, попробуйте снова!" << std::endl;
			}
		}
	}

	// Вывод элементов одномерного массива с использованием указателей
	void task_1()
	{
		std::cout << "Задание 1: Вывод элементов одномерного массива с использованием указателей" << "\n";
		std::cout << "Введите кол-во элементов массива: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;

		//int cnt = read_int(INT_MAX);
		//if (cnt == INT_MAX)
		//	return;

		/*int cnt;
		if (!to_number(squant, &cnt))
		{
			std::cout << "Ошибка: должно быть введено число!" << "\n";
			return;
		}
		*/
		// [  ][  ][  ] .. cnt
		// ^arr
		//	   ^ptr

		int* arr = new int[cnt];
		std::cout << "Введите элементы массива:" << "\n";
		int i = 0;
		do
		{
			int* elem = new int;
			std::cin >> *elem;
			arr[i] = *elem;
			delete elem;
			++i;
		} while (i != cnt);

		std::cout << "Массив: ";
		int* ptr = arr;
		for (int j = 0; j < cnt; ++j)
		{
			std::cout << *ptr << "\t";
			++ptr;
		}
		std::cout << std::endl;
		delete[] arr;
	}

	// Нахождения суммы элементов одномерного массива с помощью указателей
	void task_2()
	{
		std::cout << "Задание 2: Нахождения суммы элементов одномерного массива с помощью указателей" << "\n";
		std::cout << "Введите кол-во элементов массива: ";
		int quant = n_ReadInt(INT_MAX);
		if (quant == INT_MAX)
			return;
		int* arr;
		arr = new int[quant];
		std::cout << "Введите элементы массива:" << "\n";
		int i = 0;
		do
		{
			int elem;
			std::cin >> elem;
			arr[i] = elem;
			++i;
		} while (i != quant);
		int* ptr = arr;
		int summ = 0;
		for (int j = 0; j < quant; ++j)
		{
			summ += *ptr;
			++ptr;
		}
		std::cout << "Сумма элементов массива: " << summ << "\n";
		std::cout << std::endl;
		delete[] arr;
	}

	//Транспонирование матрицы
	void task_3()
	{
		//const char* s = "test";
	//	matrix = [ptr][ptr][ptr]
	//			 [int][int][int]
	//		     [   ][   ][   ]
	//		     [   ][   ][   ]
		std::cout << "Задание 3: Транспонирование матрицы" << std::endl;
		char buff[50];
		std::ifstream fin("matrix.txt");
		int row = 3, col = 3, cnt;
		int** matrix = new int* [row];
		for (int i = 0; i < row; ++i)
		{
			matrix[i] = new int[col];
			std::string ex;
			fin.getline(buff, 50);
			int k = 0;
			for (int j = 0; j < strlen(buff); ++j)
			{
				if (buff[j] != ' ')
				{
					ex += buff[j];
				}
				else
				{
					to_number(ex, &cnt);
					matrix[i][k] = cnt;
					std::cout << matrix[i][k] << "\t";
					ex = "";
					++k;
				}
			}
			to_number(ex, &cnt);
			matrix[i][k] = cnt;
			std::cout << matrix[i][k];
			std::cout << std::endl;
			ex = "";
			++k;
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = i + 1; j < col; ++j)
			{
				int c = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = c;
			}
		}
		int** ptr = matrix;
		std::cout << "Транспонированная матрица:" << std::endl;
		for (int i = 0; i < row; ++i)
		{
			int* row_ptr = matrix[i];
			for (int j = 0; j < col; ++j)
			{
				std::cout << *row_ptr << "\t";
				++row_ptr;
			}
			++ptr;
			std::cout << "\n";
		}
		for (int i = 0; i < row; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	//Скалярное произведение векторов
	void task_4()
	{
		std::cout << "Задание 4: Скалярное произведение векторов" << "\n";
		std::cout << "Введите длинну векторов: ";
		int len = n_ReadInt(INT_MAX);
		if (len == INT_MAX)
			return;
		std::cout << "Введите координаты первого вектора:" << std::endl;
		double* arr = new double[len];
		for (int i = 0; i < len; ++i)
		{
			double b = n_ReadInt(INT_MAX);
			if (b == INT_MAX)
				return;
			arr[i] = b;
		}
		std::cout << "Введите координаты второго вектора:" << std::endl;
		double* lst = new double[len];
		for (int i = 0; i < len; ++i)
		{
			double a = n_ReadInt(INT_MAX);
			if (a == INT_MAX)
				return;
			lst[i] = a;
		}
		double* ptra = arr;
		double* ptrl = lst;
		double scalar = 0;
		for (int i = 0; i < len; ++i)
		{
			scalar += *ptra * *ptrl;
			++ptra;
			++ptrl;
		}
		std::cout << "Скалярное произведение двух векторов: " << scalar << "\n";
		delete[] arr;
		delete[] lst;
	}

	// Основная функция
	void lab_04()
	{
		menu();
	}

} // namespace