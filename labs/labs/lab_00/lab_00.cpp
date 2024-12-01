#include <windows.h>
#include <iostream>
#include <math.h> //модуль с арифметическими действиями
#include <ctime>
#include "../my_lib.h"
#include "lab_00.h"

namespace lab_00
{
    // смена названий
    void task_1(); 
    void task_2(); 
    void task_3(); 
    void task_4(); 
    void task_5();

    // Вывод меню и получение выбора пользователя
    char select_task()
    {
        char a = 0;
        std::cout << "Выберите задание (a, b, c, d, e): \n"
            " (a) task_1\n"
            " (b) task_2\n"
            " (c) task_3\n"
            " (d) task_4\n"
            " (e) task_5" << std::endl;
        std::cin >> a;
        std::cout << std::endl;
        return a;
    }

    // Вывод основного меню
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
                case '0': std::cout << "Выход" << std::endl; break;
                default:  std::cout << "Неверный ввод" << std::endl;
            }
        } // while
    }

    // Задание на вывод имени.
    void task_1()
    {
        std::string name = "";

        std::cout << "Задание 1: Вывод имени" << std::endl;
        std::cout << "Введите имя: ";
        std::cin >> name;
        std::cout << "Здравствуй, " << name << std::endl;
        std::cout << std::endl;
    }

    // Проверка на число (возврат успешности преобразования)
    bool to_number(std::string s, double *num)
    {
        if (s.size() == 0)
            return false;
        char *pEnd;
        (*num) = strtod(s.c_str(), &pEnd);
        return (strlen(pEnd) == 0);
    }

    // Арифметика с числами 'a' и 'b'
    void task_2()
    {
        std::string sa, sb;

        std::cout << "Задание 2: Арифметика" << std::endl;
        std::cout << "Введите два числа a и b:" << std::endl;
        std::cout << "a = ";
        std::cin >> sa; 
        double a;
        if (!to_number(sa, &a))
        {
            std::cout << "Ошибка: 'a' должно быть числом" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b))
        {
            std::cout << "Ошибка: 'b' должно быть числом" << std::endl;
            std::cout << std::endl;
            return;
        }

        std::cout << "Сумма: " << a << " + " << b << " = " << a + b;
        std::cout << std::endl;
        std::cout << "Разность: " << a << " - " << b << " = " << a - b;
        std::cout << std::endl;
        std::cout << "Произведение: " << a << " * " << b << " = " << a * b;
        std::cout << std::endl;
        if (b == 0)
        {
            std::cout << "Ошибка: деление на '0' не производится!" << std::endl;
            std::cout << std::endl;
        }
        else
        {
            double x = a / b;
            std::cout << "Частное от деления: " << a << " / " << b << " = " << x << std::endl;
            std::cout << std::endl;
        }
    }

    // Решение уравнения
    void task_3()
    {
        std::string sb, sc;

        std::cout << "Задание 3: Решение уравнения (bx + c = 0)" << std::endl;
        std::cout << "Введите два числа b, с:" << std::endl;
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b) || b == 0)
        {
            std::cout << "Ошибка: 'b' должно быть ненулевым числом!" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "c = ";
        std::cin >> sc;
        double c;
        if (!to_number(sc, &c))
        {
            std::cout << "Ошибка: 'c' должно быть числом" << std::endl;
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

    // Решение квадратного уравнения
    void task_4()
    {
        std::string sa, sb, sc;

        std::cout << "Задание 4: Решение квадратного уравнения (ax^2 + bx + c = 0)" << std::endl;
        std::cout << "Введите два числа a, b, с:" << std::endl;
        std::cout << "a = ";
        std::cin >> sa; 
        double a;
        if (!to_number(sa, &a) ||a == 0)
        {
            std::cout << "Ошибка: 'a' должно быть ненулевым числом" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "b = ";
        std::cin >> sb;
        double b;
        if (!to_number(sb, &b))
        {
            std::cout << "Ошибка: 'b' должно быть числом" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << "с = ";
        std::cin >> sc;
        double c;
        if (!to_number(sc, &c))
        { 
            std::cout << "Ошибка: 'c' должно быть числом" << std::endl;
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
                std::cout << "Нет действительных корней" << std::endl;
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
                std::cout << "Нет действительных корней" << std::endl;
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

    // Проверка правильного ввода
    int check_YesNo(std::string s)
    {
        if (s == "да") return 1;
        if (s == "нет") return 0;
        return -1;
    }

    // Светло ли в комнате?
    void task_5()
    {
        std::string curtains, lamp;
        int t;
    
        std::cout << "Задание 5: Лампа со шторой" << std::endl;

        std::time_t time_utc = std::time(NULL);
        //std::time(&time_utc);
        tm timeinfo;
        localtime_s(&timeinfo, &time_utc);

        std::cout << "Текущий час: " << timeinfo.tm_hour << ":" << timeinfo.tm_min << std::endl;
        t = timeinfo.tm_hour * 60 + timeinfo.tm_min;
        int day_time = 0;
        if (12 * 60 <= t && t <= 17 * 60)
        {
            day_time = 1;
        }

        int curtains_open = -1;
        do {
            std::cout << "Раздвинуты ли шторы? [да/нет] ";
            std::cin >> curtains;
            curtains_open = check_YesNo(curtains);
        } while (curtains_open < 0);

        int lamp_on = -1;
        do {
            std::cout << "Включена ли лампа? [да/нет] ";
            std::cin >> lamp;
            lamp_on = check_YesNo(lamp);
        } while (lamp_on < 0);
    
        if ((day_time == 1 && curtains_open == 1) || (lamp_on == 1))
        {
            std::cout << "Сейчас в комнате светло!" << std::endl;
            std::cout << std::endl;
        }
        else 
        {
            std::cout << "Сейчас в комнате темно!" << std::endl;
            std::cout << std::endl;
        }
    }
}