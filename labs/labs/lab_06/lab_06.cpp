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

		std::cout << "�������� ������� �� ������: \n"
			"(1) �������� � ���� (first) \n"
			"(2) ��������� ���� (first) \n"
			"(3) �������� ����� ������ � ���� (first) \n"
			"(4) �������� ��������� ������ (fourth) \n"
			"(5) ����������� ����� (fifth) \n" << std::endl;
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
				case '1': task_1(); break;
				case '2': task_2(); break;
				case '3': task_3(); break;
				case '4': task_4(); break;
				case '5': task_5(); break;
				case '0': std::cout << "����� �� ���������" << std::endl; break;
				default: std::cout << "������������ ����, ���������� �����" << std::endl;
			}
		}
	}

	void task_1()
	{
		std::cout << "������� 1: �������� ���������� �����, � ������ � ���� ��������� �����." << std::endl;
		std::cout << "������� ����� �� ������ ������? ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::ofstream my_file("lab_06/first.txt");
		std::string s;
		while (a != 0)
		{
			std::cout << "������� �������, ������� ������ �������� ����: ";
			std::cin >> s;
			my_file << s;
			my_file << std::endl;
			--a;
		}
		my_file.close();
	}

	void task_2()
	{
		std::cout << "������� 2: ������ ������ �� �����." << std::endl;
		std::ifstream fin("lab_06/first.txt", std::ios::binary);
		std::cout << "������ �� �����:" << std::endl;


		char buff[32];
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
		std::cout << "������� 3: ��������� ����� ������ � ������������ ��������� ���� ��� �������� ���������� ������." << std::endl;
		std::cout << "������� ����� �� ������ ������? ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::fstream MyFile("lab_06/first.txt", std::ios::app);
		std::string s;
		while (a != 0)
		{
			std::cout << "������� �������, ������� ������ �������� ����: ";
			std::cin >> s;
			MyFile << s;
			MyFile << std::endl;
			--a;
		}
		MyFile.close();
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
		std::cout << "������� 4: ������ ��������� ������ � ���� � ����������� ������ �� ����." << std::endl;
		std::cout << "������� ���������� X ��� �����: ";
		point.x = n_ReadInt(INT_MAX);
		if (point.x == INT_MAX)
			return;
		std::cout << "������� ���������� Y ��� �����: ";
		point.y = n_ReadInt(INT_MAX);
		if (point.y == INT_MAX)
			return;
		std::cout << "������� ���������� Z ��� �����: ";
		point.z = n_ReadInt(INT_MAX);
		if (point.z == INT_MAX)
			return;
		std::cout << "������� ���� �����: ";
		std::cin >> point.color;

		std::ofstream outFile("lab_06/fourth.txt", std::ios::binary);
		outFile.write((char*) &point, sizeof(point));
		outFile.close();

		std::ifstream inFile("lab_06/fourth.txt", std::ios::binary);
		inFile.read((char*)&point, sizeof(point));
		inFile.close();

		std::cout << "���������� ����� x: " << point.x << std::endl;
		std::cout << "���������� ����� y: " << point.y << std::endl;
		std::cout << "���������� ����� z: " << point.z << std::endl;
		std::cout << "���� �����: " << point.color << std::endl;
		std::cout << sizeof(point.x) << std::endl;
		std::cout << sizeof(point) << std::endl;
	}

	void task_5()
	{
		std::cout << "������� 5: ������������ ����������� ������ ����� � ������." << std::endl;
		char buff[32];
		std::ifstream fin("lab_06/fourth.txt", std::ios::binary);
		std::ofstream file("lab_06/fifth.txt", std::ios::binary);
		do
		{
			fin.read(buff, sizeof(buff) - 1);
			file.write(buff, fin.gcount());
		} while (!fin.eof());
		fin.close();
		file.close();
		char temp_2[32];
		std::ifstream fin_2("lab_06/fifth.txt");
		std::cout << "���������� ������� �����: " << std::endl;
		do
		{
			fin_2.read(temp_2, sizeof(temp_2) - 1);
			temp_2[fin_2.gcount()] = '\0';
			std::cout << temp_2;
		} while (!fin_2.eof());
		fin_2.close();
	}
} // namespace