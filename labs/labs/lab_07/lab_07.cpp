#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../my_lib.h"
#include "lab_07.h"

namespace lab_07
{
	void task_1();
	void task_2();
	void task_3();
	void task_4();

	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(1) Информация про класс <Студент> \n"
			"(2) Создание нескольких объектов класса \n"
			"(3) Подсчет среднего балла \n"
			"(4) Работа с библеотекой \n" << std::endl;
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
			case '0': std::cout << "Выход из программы" << std::endl; break;
			default: std::cout << "Неправильный ввод, попробуйте снова" << std::endl;
			}
		}
	}

	class Student {
	private:
		std::string name;
		int age;
		double average_score;
		std::vector<double> grades;

	public:
		//конструктор
		Student(std::string n, int a, double as)
		{
			name = n;
			age = a;
			average_score = as;
		}

		void info()
		{
			std::cout << "Имя: " << name << std::endl;
			std::cout << "Возраст: " << age << std::endl;
			std::cout << "Средний балл: " << average_score << std::endl;

		}
		//Метод добавления отметок в вектор
		void addgrade(double grade)
		{
			grades.push_back(grade);
		}

		double cal_avg()
		{
			if (grades.empty())
				return 0;
			else
			{
				double sum = 0;
				for (int i = 0; i != grades.size(); ++i)
				{
					sum += grades[i];
				}
				return sum / grades.size();
			}
		}

		//Информация для случая среднего балла на основе отметок
		void info_2()
		{
			std::cout << "Имя: " << name << std::endl;
			std::cout << "Возраст: " << age << std::endl;
			std::cout << "Средний балл: " << cal_avg() << std::endl;
		}
	};

	void task_1()
	{
		std::cout << "Задание 1: Создание класса и вывод информации" << std::endl;
		std::cout << "Введите ФИО студента: ";
		std::string name;
		std::cin >> name;
		std::cout << "Введите возраст студента: ";
		int age = n_ReadInt(INT_MAX);
		if (age == INT_MAX)
			return;
		std::cout << "Введите средний балл студента: ";
		double avg = n_ReadDouble(INT_MAX);
		if (avg == INT_MAX)
			return;
		Student student1(name, age, avg);
		student1.info();
		std::cout << std::endl;
	}

	void task_2()
	{
		std::cout << "Задание 2: Создание нескольких объектов класса" << std::endl;
		std::cout << "Сколько студентов вы хотите внести: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		std::vector<Student> students;
		do {
			std::cout << "Введите ФИО студента: ";
			std::string name;
			std::cin >> name;
			std::cout << "Введите возраст студента: ";
			int age = n_ReadInt(INT_MAX);
			if (age == INT_MAX)
				return;
			std::cout << "Введите средний балл студента: ";
			double avg = n_ReadDouble(INT_MAX);
			if (avg == INT_MAX)
				return;
			Student student1(name, age, avg);
			students.emplace_back(student1);
			cnt -= 1;
		} while (cnt != 0);
		for (int i = 0; i != students.size(); ++i)
		{
			students[i].info();
		}
		std::cout << std::endl;
	}

	void task_3()
	{
		std::cout << "Задание 3: Подсчета среднего балла студента на основе оценок по нескольким предметам" << std::endl;
		std::cout << "Введите ФИО студента: ";
		std::string name;
		std::cin >> name;
		std::cout << "Введите возраст студента: ";
		int age = n_ReadInt(INT_MAX);
		if (age == INT_MAX)
			return;
		std::cout << "Сколько отметок вы хотите внести: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		Student student1(name, age, 0);
		double a;
		while (cnt != 0)
		{
			std::cin >> a;
			student1.addgrade(a);
			cnt -= 1;
		}
		student1.info_2();
		std::cout << std::endl;
	}

	class Book {
	private:
		std::string title;
		std::string author;
		int year;

	public:
		Book(std::string t, std::string a, int y)
		{
			title = t;
			author = a;
			year = y;
		}

		//Название книги
		std::string gettitle() const
		{
			return title;
		}

		void info()
		{
			std::cout << "Название: " << title << ", Автор: " << author << ", Год издания: " << year << std::endl;
		}
	};

	class Library {
	private: 
		std::vector<Book> books;

	public:
		//Метод добавления книги
		void addbook(const Book& book)
		{
			books.push_back(book);
			std::cout << "Книга " << book.gettitle() << " добавлена в библиотеку." << std::endl;
		}

		void removebook(const std::string& title)
		{
			for (auto it = books.begin(); it != books.end(); ++it) {
				if (it->gettitle() == title) {
					books.erase(it);
					std::cout << "Книга \"" << title << "\" удалена." << std::endl;
					return;
				}
			}
			std::cout << "Книга \"" << title << "\" не найдена." << std::endl;
		}
		void disinfo()
		{
			for (int i = 0; i != books.size(); ++i)
			{
				books[i].info();
			}
		}
	};

	void task_4()
	{	
		Library library;
		std::cout << "Задание 4: Работа с Библиотекой" << std::endl;
		std::cout << "Сколько книг вы хотите добавить: ";
		int cnt = n_ReadInt(INT_MAX);
		if (cnt == INT_MAX)
			return;
		for (int i = 0; i != cnt; ++i)
		{
			std::cout << "Введите название книги: ";
			std::string title;
			std::cin >> title;
			std::cout << "Введите автора книги: ";
			std::string author;
			std::cin >> author;
			std::cout << "Введите год издания: ";
			int year = n_ReadInt(INT_MAX);
			if (year == INT_MAX)
				return;
			library.addbook(Book(title, author, year));
		}
		/*std::cout << "Сколько книг вы хотите удалить: ";
		int cnt_1 = n_ReadInt(INT_MAX);
		if (cnt_1 == INT_MAX)
			return;
		for (int i = 0; i != cnt_1; ++i)
		{
			std::string title;
			std::cout << "Введите название книги, которую хотите удалить: ";
			std::cin >> title;
			library.removebook(title);
		}*/
		library.disinfo();
	}
}