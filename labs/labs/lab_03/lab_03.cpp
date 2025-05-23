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

	//���������������� ����
	char select_task()
	{
		char a = '-';

		std::cout << "�������� ������� �� ������: \n"
			"(a) ������� 1 (for)\n"
			"(b) ������� 1 (while)\n"
			"(c) ������� 2 (for)\n"
			"(d) ������� 2 (while)\n"
			"(e) ������� 3 (for)\n"
			"(f) ������� 3 (while)\n"
			"(g) ������� 4 (for)\n"
			"(h) ������� 4 (while)" << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	// ���������������� ����
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
			case '0': std::cout << "����� �� ���������" << std::endl; break;
			default: std::cout << "������������ ����, ���������� �����" << std::endl;
			}
		}
	}

	// ����� ������� ��������� (for)
	void task_1()
	{
		std::string sa;
		std::cout << "������� 1: ����� ������� ��������� ��� ����������� �����" << std::endl;
		std::cout << "������� �����, ��� ���������� ��������� �������: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������!" << "\n";
			return;
		}
		std::cout << "�������� ������� ���������:" << std::endl;
		for (int i = 1; i < 11; ++i)
		{
			std::cout << a * i << "\t";
		}
		std::cout << std::endl << "\n";
	}

	// ����� ������� ��������� (while)
	void task_2()
	{
		std::string sa;

		std::cout << "������� 1: ����� ������� ��������� ��� ����������� �����" << std::endl;
		std::cout << "������� �����, ��� ���������� ��������� �������: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������!" << "\n";
			return;
		}
		int i = 1;
		std::cout << "�������� ������� ���������:" << std::endl;
		while (i < 11)
		{
			std::cout << i * a << "\t";
			++i;
		}
		std::cout << std::endl << "\n";
	}

	// ����� ����� �� 1 �� N (for)
	void task_3()
	{
		std::string sa;

		std::cout << "������� 2: ����� ����� �� 1 �� N" << std::endl;
		std::cout << "������� �����: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "������: 'N' ������ ���� ������!" << "\n";
			return;
		}
		int summ = 0;
		for (int i = 1; i < a + 1; ++i)
		{
			summ += i;
		}
		std::cout << "����� ���������� " << summ << std::endl << "\n";
	}

	// ����� ����� �� 1 �� N (while)
	void task_4()
	{
		std::string sa;

		std::cout << "������� 2: ����� ����� �� 1 �� N" << std::endl;
		std::cout << "������� �����: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		double a;
		if (!to_double(sa, &a))
		{
			std::cout << "������: 'N' ������ ���� ������!" << "\n";
			return;
		}
		int summ = 0, i = 1;
		while (i < a + 1)
		{
			summ += i;
			++i;
		}
		std::cout << "����� ���������� " << summ << std::endl << "\n";
	}

	// �������� �� ��������� ����� ������� (for)
	void task_5()
	{
		std::string sa;

		std::cout << "������� 3: �������� �� ��������� ����� �������?" << std::endl;
		std::cout << "������� �����, ������� ������ ���������: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������!" << "\n";
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
			std::cout << "����� " << a << " �������� �������!" << std::endl << "\n";
		}
		else
		{
			std::cout << "����� " << a << " �� �������� �������!" << std::endl << "\n";
		}
	}

	// �������� �� ��������� ����� ������� (while)
	void task_6()
	{
		std::string sa;

		std::cout << "������� 3: �������� �� ��������� ����� �������?" << std::endl;
		std::cout << "������� �����, ������� ������ ���������: " << std::endl;
		std::cout << "a = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "������: 'a' ������ ���� ������!" << "\n";
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
			std::cout << "����� " << a << " �������� �������!" << std::endl << "\n";
		}
		else
		{
			std::cout << "����� " << a << " �� �������� �������!" << std::endl << "\n";
		}
	}

	// ��������� ����� (for)
	void task_7()
	{
		std::cout << "������� 4: ��������� �����" << std::endl;
		std::cout << "������� �����: " << std::endl;
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
		std::cout << "��������� ����� " << a << " ���������� " << factorial << std::endl << "\n";
	}

	// ��������� ����� (while)
	void task_8()
	{
		std::string sa;

		std::cout << "������� 4: ��������� �����" << std::endl;
		std::cout << "������� �����: " << std::endl;
		std::cout << "N = ";
		std::cin >> sa;
		int a;
		if (!to_number(sa, &a))
		{
			std::cout << "������: 'N' ������ ���� ������!" << "\n";
			return;
		}
		int factorial = 1, i = 1;
		while (i < a + 1)
		{
			factorial *= i;
			++i;
		}
		std::cout << "��������� ����� " << a << " ���������� " << factorial << std::endl << "\n";
	}

} // namespace