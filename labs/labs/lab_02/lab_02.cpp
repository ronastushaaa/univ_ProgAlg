#include <windows.h> // ���������� ��� ���������
#include <iostream>
#include "../my_lib.h"
#include "lab_02.h"

namespace lab_02
{
	void task_1();
	void task_2();
	void task_3();
	void task_4();

	// ����� ���� � ��������� ������ ������������
	char select_task()
	{
		char a = '-'; 
		std::cout << "�������� �������, ������� ��� ���������� (a, b, c, d): \n"
			" (a) task_1 \n"
			" (b) task_2 \n"
			" (c) task_3 \n"
			" (d) task_4 " << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	// ����� ��������� ����
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
				case '0': std::cout << "����� �� ���������." << std::endl; break;
				default: std::cout << "����������� ����" << std::endl;
			}
		}
	}

	// �������� �� ����� ����� (���������� ���������� ��������������)
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


	// ������� �� �������� ��������
	void task_1()
	{
		std::string sa;

		std::cout << "������� 1: �������� ����� �� ��������." << std::endl;
		std::cout << "������� �����, ������� ������ ���������: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_integer(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (a % 2 == 0)
		{
			std::cout << "����� a = " << a << " ������!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "����� a = " << a << " ��������!" << std::endl;
			std::cout << std::endl;
		}
	}

	// �������� �� ��������� ���
	void task_2()
	{
		std::string sa;

		std::cout << "������� 2: ���������� �� ���?" << std::endl;
		std::cout << "������� ���, ������� ������ ���������:" << std::endl;
		std::cout << "��� - ";
		std::cin >> sa;
		int year;
		if (!to_integer(sa, &year))
		{
			std::cout << "������: 'year' ������ ���� ������!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if ((year % 4 == 0 && !(year % 100 == 0)) || (year % 100 == 0 && year % 400 == 0))
		{
			std::cout << year << " ��� �������� ���������!" << std::endl;
			std::cout << std::endl;
		}
		else if (year % 100 == 0)
		{
			std::cout << year << " ��� �� �������� ���������!" << std::endl;
			std::cout << std::endl;
		}
	}

	// �������� �� ����� (���������� ���������� ��������������)
	bool to_double(std::string s, double* num)
	{
		if (s.size() == 0)
			return false;
		char* pEnd;
		(*num) = strtold(s.c_str(), &pEnd);
		return (strlen(pEnd) == 0);

	}

	// ����� ������������� ����� �� ���
	void task_3()
	{
		std::string sa, sb, sc;

		std::cout << "������� 3: ����� ������������� ����� �� ���" << std::endl;
		std::cout << "������� ��� ����� a, b � c:" << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������!" << std::endl;
			std::cout << std::endl;
			return;
		}
		std::cout << "b = ";
		std::cin >> sb;
		double b;
		if (!to_double(sb, &b))
		{
			std::cout << "������: 'b' ������ ���� ������!" << std::endl;
			std::cout << std::endl;
			return;
		}
		std::cout << "c = ";
		std::cin >> sc;
		double c;
		if (!to_double(sc, &c))
		{
			std::cout << "������: 'c' ������ ���� ������!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (a >= b && a >= c)
		{
			std::cout << "����� " << a << " ����� ������������!";
			std::cout << std::endl;
		}
		else if (b >= a && b >= c)
		{
			std::cout << "����� " << b << " ����� ������������!";
			std::cout << std::endl;
		}
		else
		{
			std::cout << "����� " << c << " ����� ������������!";
			std::cout << std::endl;
		}
	}

	// �������� �� ��������� ����� ������� ��� ���������
	void task_4()
	{
		std::string vowels = "AaEeIiOoUuYy�����������������娸";


		//int ord_a = (int)'a';
		//int ord_z = (int)'z';

		//IsCharAlpha

		std::string letter = "";
		std::cout << "������� 4: �������� �� ��������� ����� ������� ��� ���������" << std::endl;
		std::cout << "������� ����� �� ��������" << std::endl;
		std::cout << "����� - ";
		std::cin >> letter;
		if (to_integer(letter))
		{
			std::cout << "������: ������ ���� ������� �����!" << std::endl;
			std::cout << std::endl;
			return;
		}
		else if (letter.size() != 1)
		{
			std::cout << "������: ������ ���� ������� �����!" << std::endl;
			std::cout << std::endl;
			return;
		}
		if (vowels.find(letter) < vowels.size())
		{
			std::cout << vowels.find(letter);
			std::cout << "����� '" << letter << "' �������� �������!" << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "����� '" << letter << "' �������� ���������!" << std::endl;
			std::cout << std::endl;
		}
	} 
}