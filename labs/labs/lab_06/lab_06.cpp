#include <iostream>
#include <fstream>
#include <cmath>
#include "../my_lib.h"
#include "lab_06.h"

namespace lab_06
{
	void task_1();
	void task_2();
	void task_3();
	void task_4();
	void task_5();

	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(a) Задание 1 \n"
			"(b) Задание 2 \n"
			"(c) Задание 3 \n"
			"(d) Задание 4 \n"
			"(e) Задание 5 \n" << std::endl;
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

	void task_1()
	{
		std::cout << "Задание 1: Создание текстового файла, и запись в него несколько строк." << std::endl;
		std::cout << "Сколько строк вы хотите ввести? ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::ofstream MyFile("lab_06/first.txt");
		std::string s;
		int b = a;
		while (a != 0)
		{
			std::cout << "Введите строчку, которую хотите добавить файл: ";
			std::cin >> s;
			MyFile << s;
			MyFile << std::endl;
			--a;
		}
		MyFile.close();
	}

	void task_2()
	{
		std::cout << "Задание 2: Чтение данных из файла." << std::endl;
		std::ifstream fin("lab_06/first.txt", std::ios::binary);
		std::cout << "Данные из файла:" << std::endl;


		char buff[5];
		do {
			fin.read(buff, sizeof(buff) - 1);
			buff[fin.gcount()] = '\0';
			std::cout << buff;
		} while (!fin.eof());
		fin.close();
		std::cout << std::endl << std::endl;
	}

	void task_3()
	{
		std::cout << "Задание 3: Добавляет новые строки в существующий текстовый файл без удаления предыдущих данных." << std::endl;
		std::cout << "Сколько строк вы хотите ввести? ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::fstream MyFile("lab_06/first.txt", std::ios::app);
		std::string s;
		int b = a;
		while (a != 0)
		{
			std::cout << "Введите строчку, которую хотите добавить файл: ";
			std::cin >> s;
			MyFile << s;
			MyFile << std::endl;
			--a;
		}
		MyFile.close();
		std::cout << std::endl;
		std::cout << "Содержание файла:" << std::endl;
		char buff[5];
		std::ifstream fin("lab_06/first.txt");
		do
		{
			fin.read(buff, sizeof(buff) - 1);
			buff[fin.gcount()] = '\0';
			std::cout << buff;
		} while (!fin.eof());
		fin.close();
		std::cout << std::endl;
	}

	struct Point {
		double x;
		double y;
		double z;
		std::string color;
	};

	void task_4()
	{
		Point point;
		std::cout << "Задание 4: Запись структуры данных в файл и последующее чтение из него." << std::endl;
		std::cout << "Введите координату X для точки: ";
		point.x = n_ReadInt(INT_MAX);
		if (point.x == INT_MAX)
			return;
		std::cout << "Введите координату Y для точки: ";
		point.y = n_ReadInt(INT_MAX);
		if (point.y == INT_MAX)
			return;
		std::cout << "Введите координату Z для точки: ";
		point.z = n_ReadInt(INT_MAX);
		if (point.z == INT_MAX)
			return;
		std::cout << "Введите цвет точки: ";
		std::cin >> point.color;

		std::ofstream outFile("lab_06/fourth.txt", std::ios::binary);
		outFile.write((char*) &point, sizeof(point));
		outFile.close();

		std::ifstream inFile("lab_06/fourth.txt", std::ios::binary);
		inFile.read((char*)&point, sizeof(point));
		inFile.close();

		//std::cout << "Имя: " << person.name << ", Возраст: " << person.age << std::endl;
		std::cout << "Координата точки x: " << point.x << std::endl;
		std::cout << "Координата точки y: " << point.y << std::endl;
		std::cout << "Координата точки z: " << point.z << std::endl;
		std::cout << "Цвет точки: " << point.color << std::endl;
	}

	void task_5()
	{
		std::cout << "Задание 5: Копированние содержимого одного файла в другой." << std::endl;
		char buff[5];
		std::ifstream fin("lab_06/fifth_1.txt");
		std::ofstream file("lab_06/fifth_2.txt");
		std::cout << "Данные из файла:" << std::endl;
		do
		{
			fin.read(buff, sizeof(buff) - 1);
			buff[fin.gcount()] = '\0';
			file << buff;
			std::cout << buff;
		} while (!fin.eof());
		fin.close();
		file.close();
		char temp_2[5];
		std::ifstream fin_1("lab_06/fifth_1.txt");
		std::ifstream fin_2("lab_06/fifth_2.txt");
		std::cout << "Содержание второго файла: " << std::endl;
		do
		{
			fin_2.read(temp_2, sizeof(temp_2) - 1);
			temp_2[fin_2.gcount()] = '\0';
			std::cout << temp_2;
		} while (!fin_2.eof());
		fin_1.close();
		fin_2.close();
	}
} // namespace