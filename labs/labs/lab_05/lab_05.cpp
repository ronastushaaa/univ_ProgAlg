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

	//���������������� ����
	char select_task()
	{
		char a = '-';

		std::cout << "�������� ������� �� ������: \n"
			"(a) ������� 1 \n"
			"(b) ������� 2\n"
			"(c) ������� 3\n"
			"(d) ������� 4\n"
			"(e) ������� 5\n" << std::endl;
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
			case '0': std::cout << "����� �� ���������" << std::endl; break;
			default: std::cout << "������������ ����, ���������� �����" << std::endl;
			}
		}
	}

	// ������� ���������� ����������
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

	// ����� ��������� �����
	void task_1()
	{
		std::cout << "������� 1: ����� ��������� �����" << std::endl;
		std::cout << "������� �����, ��� ���������� ����������: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "��������� �����: " << a << " ����� " << factorial(a) << std::endl;
		std::cout << std::endl;
	}

	// �������� �������
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

	// ��� ���� �����
	void task_2()
	{
		std::cout << "������� 2: ����� ����������� ������ �������� 2� �����" << std::endl;
		std::cout << "������� ������ �����: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "������� ������ �����: " << std::endl;
		std::cout << "b = ";
		int b = n_ReadInt(INT_MAX);
		if (b == INT_MAX)
			return;
		std::cout << "��� ����� " << a << " � " << "����� " << b << " �����: " << nod(a, b) << std::endl;
		std::cout << std::endl;
	}

	// �������� ������� �� �����
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
			std::cout << "��������� ����� a = " << a << " �������� �������" << std::endl;
		else
			std::cout << "��������� ����� a = " << a << " �� �������� �������" << std::endl;
	}

	// �������� �� ��������� ����� ������� 
	void task_3()
	{
		std::cout << "������� 3: �������� �� ��������� ����� �������?" << std::endl;
		std::cout << "������� �����: " << std::endl;
		std::cout << "N = ";
		double a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		prime_number(a);
		std::cout << std::endl;
	}

	// �������� �� ���������
	void palindrom(std::string a)
	{
		int j = 0;
		for (int i = a.size(); --i > (a.size() / 2); )
		{
			if (a[j] != a[i])
			{
				std::cout << "��������� ������ " << a << " �� �������� �����������" << std::endl;
				break;
			}
			++j;
		}
		if (j == a.size() / 2)
			std::cout << "��������� ������ " << a << " �������� �����������" << std::endl;
	}

	// �������� �� ��������� ������ �����������
	void task_4()
	{
		std::string s;
		std::cout << "������� 4: �������� �� ��������� ������ �����������?" << std::endl;
		std::cout << "������� ������: ";
		std::cin >> s;
		palindrom(s);
	}

	// ����� ���������
	int fibonacci_number(int a)
	{
		if (a == 1)
			return 1;
		else if (a == 0)
			return 0;
		else
			return fibonacci_number(a - 2) + fibonacci_number(a - 1);
	}

	// ���������� ����� ���������
	void task_5()
	{
		std::cout << "������� 5: ����� ����� ���������" << std::endl;
		std::cout << "������� ������� �����: " << std::endl;
		std::cout << "a = ";
		int a = n_ReadInt(INT_MAX);
		if (a == INT_MAX)
			return;
		std::cout << "����� ���������: ";
		int i = 0;
		while (i != a + 1)
		{
			std::cout << fibonacci_number(i) << "\t";
			++i;
		}
		std::cout << std::endl;
	}
} // namespace