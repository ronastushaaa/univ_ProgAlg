#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../my_lib.h"
#include "lab_11.h"
#include <time.h>

namespace lab_11
{
	
	void bubble_sort();
	void insertion_sort();
	void merge_sort();

	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(1) Сортировка пузырьком <Bubble Sort> \n"
			"(2) Сортировка вставками <Insertion_sort> \n"
			"(3) Сортировка слиянием <Merge_sort> \n" << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	void menu()
	{
		char a = '-';
		while (a != '0')
		{
			a = select_task();
			switch (a)
			{
			case '1': bubble_sort(); break;
			case '2': insertion_sort(); break;
			case '3': merge_sort(); break;
			case '0': std::cout << "Выход из программы" << std::endl; break;
			default: std::cout << "Неправильный ввод, попробуйте снова" << std::endl;
			}
		}
	}

	//Функция для сортировки пузырьком
	void bubble_sort()
	{
		std::cout << "Задание 1: Сортировка пузырьком" << std::endl;
		std::cout << "Введите кол-во элементов массива: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		int* arr = new int[cnt];

		std::cout << "Введите элементы массива:" << std::endl;
		for (int i = 0; i < cnt; ++i)
		{
			arr[i] = rand();
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Отсортированный массив: " << std::endl;
		clock_t start = clock();
		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < cnt - i -  1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
		clock_t end = clock();
		for (int i = 0; i < cnt; ++i)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
		delete[] arr;
		double sec = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl;
		std::cout << "Время выполнения алгоритма <Bubble sort>: " << sec;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	//функция для сортировки вставками
	void insertion_sort()
	{
		std::cout << "Задание 2: Сортировка вставками <Insertion sort>" << std::endl;
		std::cout << "Введите кол-во элементов массива: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		int* arr = new int[cnt];

		std::cout << "Введите элементы массива:" << std::endl;
		for (int i = 0; i < cnt; ++i)
		{
			arr[i] = rand();
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Отсортированный массив: " << std::endl;
		clock_t start = clock();
		for (int i = 0; i < cnt; i++)
		{
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
		clock_t end = clock();
		for (int i = 0; i < cnt; ++i)
		{
			std::cout << arr[i] << "\t";
		}
		std::cout << std::endl;
		delete[] arr;
		double sec = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl;
		std::cout << "Время выполнения алгоритма <Insertion sort>: " << sec;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	void merge(std::vector<int>& vec, int left, int right, int middle)
	{
		int cnt_1 = middle - left + 1;
		int cnt_2 = right - middle;
		std::vector<int> v1(cnt_1);
		std::vector<int> v2(cnt_2);
		for (int i = 0; i < cnt_1; ++i)
		{
			v1[i] = vec[left + i];
		}
		for (int j = 0; j < cnt_2; ++j)
		{
			v2[j] = vec[middle + j + 1];
		}
		int i = 0, j = 0, k = left;
		while (i < cnt_1 && j < cnt_2)
		{
			if (v1[i] <= v2[j])
			{
				vec[k] = v1[i];
				++i;
			}
			else
			{
				vec[k] = v2[j];
				++j;
			}
			++k;
		}

		while (i < cnt_1)
		{
			vec[k] = v1[i];
			++i;
			++k;
		}
		while (j < cnt_2)
		{
			vec[k] = v2[j];
			++j;
			++k;
		}
	}

	void merge_sorted(std::vector<int>& vec, int left, int right)
	{
		if (left < right)
		{
			int middle = left + (right - left) / 2;
			merge_sorted(vec, left, middle);
			merge_sorted(vec, middle + 1, right);
			merge(vec, left, right, middle);
		}
	}

	//Сортировка слиянием
	void merge_sort()
	{
		std::cout << "Задание 3: Сортировка слиянием <Merge Sort>" << std::endl;
		std::cout << "Введите кол-во элементов массива: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		std::vector <int> vec(cnt);
		for (int i = 0; i < cnt; ++i)
		{
			vec[i] = rand();
			std::cout << vec[i] << "\t";
		}
		std::cout << std::endl;
		clock_t start = clock();
		merge_sorted(vec, 0, cnt - 1);
		clock_t end = clock();
		std::cout << "Отсортированный список: ";
		std::cout << std::endl;
		for (int i = 0; i < cnt; ++i)
		{
			std::cout << vec[i] << "\t";
		}
		std::cout << std::endl;
		double sec = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl;
		std::cout << "Время выполнения алгоритма <Merge sort>: " << sec;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}
	