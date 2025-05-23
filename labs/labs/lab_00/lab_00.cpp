#include <windows.h>
#include <iostream>
#include <math.h> //������ � ��������������� ����������
#include <ctime>
#include "../my_lib.h"
#include "lab_00.h"

namespace lab_00
{
    // ����� ��������
    void task_1(); 
    void task_2(); 
    void task_3(); 
    void task_4(); 
    void task_5();

    // ����� ���� � ��������� ������ ������������
    char select_task()
    {
        char a = 0;
        std::cout << "�������� ������� (a, b, c, d, e): \n"
            " (a) task_1\n"
            " (b) task_2\n"
            " (c) task_3\n"
            " (d) task_4\n"
            " (e) task_5" << std::endl;
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
                case 'e': task_5(); break;
                case '0': std::cout << "�����" << std::endl; break;
                default:  std::cout << "�������� ����" << std::endl;
            }
        } // while
    }

    // ������� �� ����� �����.
    void task_1()
    {
        std::string name = "";

        std::cout << "������� 1: ����� �����" << std::endl;
        std::cout << "������� ���: ";
        std::cin >> name;
        std::cout << "����������, " << name << std::endl;
        std::cout << std::endl;
    }

    // �������� �� ����� (������� ���������� ��������������)
    bool to_number(std::string s, double *num)
    {
        if (s.size() == 0)
            return false;
        char *pEnd;
        (*num) = strtod(s.c_str(), &pEnd);
        return (strlen(pEnd) == 0);
    }

    // ���������� � ������� 'a' � 'b'
    void task_2()
    {
        std::string sa, sb;

        std::cout << "������� 2: ����������" << std::endl;
        std::cout << "������� ��� ����� a � b:" << std::endl;
        std::cout << "a = ";
        std::cin >> sa; 
        double a;
        if (!to_number(sa, &a))
        {
            std::cout << "������: 'a' ������ ���� ������" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b))
        {
            std::cout << "������: 'b' ������ ���� ������" << std::endl;
            std::cout << std::endl;
            return;
        }

        std::cout << "�����: " << a << " + " << b << " = " << a + b;
        std::cout << std::endl;
        std::cout << "��������: " << a << " - " << b << " = " << a - b;
        std::cout << std::endl;
        std::cout << "������������: " << a << " * " << b << " = " << a * b;
        std::cout << std::endl;
        if (b == 0)
        {
            std::cout << "������: ������� �� '0' �� ������������!" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            double x = a / b;
            std::cout << "������� �� �������: " << a << " / " << b << " = " << x << std::endl;
            std::cout << std::endl;
        }
    }

    // ������� ���������
    void task_3()
    {
        std::string sb, sc;

        std::cout << "������� 3: ������� ��������� (bx + c = 0)" << std::endl;
        std::cout << "������� ��� ����� b, �:" << std::endl;
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b) || b == 0)
        {
            std::cout << "������: 'b' ������ ���� ��������� ������!" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "c = ";
        std::cin >> sc;
        double c;
        if (!to_number(sc, &c))
        {
            std::cout << "������: 'c' ������ ���� ������" << std::endl;
            std::cout << std::endl;
            return;
        }
        if (c != 0)
        {
            double a = -c / b;
            std::cout << "x = " << a << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "x = " << 0 << std::endl;
            std::cout << std::endl;
        }
    }

    // ������� ����������� ���������
    void task_4()
    {
        std::string sa, sb, sc;

        std::cout << "������� 4: ������� ����������� ��������� (ax^2 + bx + c = 0)" << std::endl;
        std::cout << "������� ��� ����� a, b, �:" << std::endl;
        std::cout << "a = ";
        std::cin >> sa; 
        double a;
        if (!to_number(sa, &a) ||a == 0)
        {
            std::cout << "������: 'a' ������ ���� ��������� ������" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b))
        {
            std::cout << "������: 'b' ������ ���� ������" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "� = ";
        std::cin >> sc;
        double c;
        if (!to_number(sc, &c))
        { 
            std::cout << "������: 'c' ������ ���� ������" << std::endl;
            std::cout << std::endl;
            return;
        }
        if (b != 0 && c != 0)
        {
            double d = pow(b, 2) - (4 * a * c);
            if (d > 0)
            {
                std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << std::endl;
                std::cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;
                std::cout << std::endl;
            }
            else if (d == 0)
            {
                std::cout << "x = " << (-b / (2 * a)) << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "��� �������������� ������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (b == 0 && c != 0)
        {
            double z = -c / a;
            if (z >= 0)
            {
                std::cout << "x1 = " << sqrt(z) << std::endl;
                std::cout << "x2 = " << -(sqrt(z)) << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "��� �������������� ������" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (c == 0 && b != 0)
        {
            double x_1 = -b / a;
            std::cout << "x1 = " << 0 << std::endl;
            std::cout << "x2 = " << x_1 << std::endl;
            std::cout << std::endl;

        }
        else if (c == 0 && b == 0)
        {
            std::cout << "x = " << 0 << std::endl;
            std::cout << std::endl;
        }
    }

    // �������� ����������� �����
    int check_YesNo(std::string s)
    {
        if (s == "��") return 1;
        if (s == "���") return 0;
        return -1;
    }

    // ������ �� � �������?
    void task_5()
    {
        std::string curtains, lamp;
        int t;
    
        std::cout << "������� 5: ����� �� ������" << std::endl;

        std::time_t time_utc = std::time(NULL);
        //std::time(&time_utc);
        tm timeinfo;
        localtime_s(&timeinfo, &time_utc);

        std::cout << "������� ���: " << timeinfo.tm_hour << ":" << timeinfo.tm_min << std::endl;
        t = timeinfo.tm_hour * 60 + timeinfo.tm_min;
        int day_time = 0;
        if (12 * 60 <= t && t <= 17 * 60)
        {
            day_time = 1;
        }

        int curtains_open = -1;
        do {
            std::cout << "���������� �� �����? [��/���] ";
            std::cin >> curtains;
            curtains_open = check_YesNo(curtains);
        } while (curtains_open < 0);

        int lamp_on = -1;
        do {
            std::cout << "�������� �� �����? [��/���] ";
            std::cin >> lamp;
            lamp_on = check_YesNo(lamp);
        } while (lamp_on < 0);
    
        if ((day_time == 1 && curtains_open == 1) || (lamp_on == 1))
        {
            std::cout << "������ � ������� ������!" << std::endl;
            std::cout << std::endl;
        }
        else 
        {
            std::cout << "������ � ������� �����!" << std::endl;
            std::cout << std::endl;
        }
    }
}