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
			"(a) ������� 1 \n"
			"(b) ������� 2 \n"
			"(c) ������� 3 \n"
			"(d) ������� 4 \n"
			"(e) ������� 5 \n" << std::endl;
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
		std::ofstream MyFile("lab_06/first.txt");
		std::string s;
		int b = a;
		while (a != 0)
		{
			std::cout << "������� �������, ������� ������ �������� ����: ";
			std::cin >> s;
			MyFile << s;
			MyFile << "\n";
			--a;
		}
		std::cout << std::endl;
		std::cout << "���������� �����:" << std::endl;
		MyFile.close();
		char buff[50];
		std::ifstream fin("lab_06/first.txt");
		fin.getline(buff, 50);
		while (fin.good())
		{
			std::cout << buff;
			std::cout << std::endl;
			fin.getline(buff, 50);
		}
		fin.close();
		std::cout << std::endl;
	}

	void task_2()
	{
		std::cout << "������� 2: ������ ������ �� �����." << std::endl;
		char buff[100];
		std::ifstream fin("lab_06/second.txt");
		std::cout << "������ �� �����:" << std::endl;
		fin.getline(buff, 100);
		while (fin.good())
		{
			std::cout << buff << std::endl;
			fin.getline(buff, 100);
		}
		std::cout << std::endl;
	}

	void task_3()
	{
		std::cout << "������� 3: ��������� ����� ������ � ������������ ��������� ���� ��� �������� ���������� ������." << std::endl;
		std::cout << "������� ����� �� ������ ������? ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::fstream MyFile("lab_06/third.txt", std::ios::app);
		std::string s;
		int b = a;
		while (a != 0)
		{
			std::cout << "������� �������, ������� ������ �������� ����: ";
			std::cin >> s;
			MyFile << s;
			MyFile << "\n";
			--a;
		}
		std::cout << std::endl;
		std::cout << "���������� �����:" << std::endl;
		MyFile.close();
		char buff[50];
		std::ifstream fin("lab_06/third.txt");
		fin.getline(buff, 50);
		while (fin.good())
		{
			std::cout << buff;
			std::cout << std::endl;
			fin.getline(buff, 50);
		}
		fin.close();
		std::cout << std::endl;
	}

	void task_4()
	{

	}

	void task_5()
	{
		std::cout << "������� 5: ������������ ���������� ������ ����� � ������." << std::endl;
		char buff[50];
		std::ifstream fin("lab_06/fifth_1.txt");
		std::ofstream file("lab_06/fifth_2.txt");
		std::cout << "������ �� �����:" << std::endl;
		fin.getline(buff, 50);
		while (fin.good())
		{
			file << buff;
			file << "\n";
			std::cout << buff << std::endl;
			fin.getline(buff, 50);
		}
		fin.close();
		file.close();
		char temp_1[50];
		char temp_2[50];
		std::ifstream fin_1("lab_06/fifth_1.txt");
		std::ifstream fin_2("lab_06/fifth_2.txt");
		std::cout << std::endl;
		std::cout << "���������� ������� �����: " << std::endl;
		fin_1.getline(temp_1, 50);
		while (fin_1.good())
		{
			std::cout << temp_1 << std::endl;
			fin_1.getline(temp_1, 50);
		}
		std::cout << std::endl;
		std::cout << "���������� ������� �����: " << std::endl;
		fin_2.getline(temp_2, 50);
		while (fin_2.good())
		{
			std::cout << temp_2 << std::endl;
			fin_2.getline(temp_2, 50);
		}
		fin_1.close();
		fin_2.close();
	}
} // namespace