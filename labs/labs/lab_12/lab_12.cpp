#include "lab_12.h"


namespace lab_12
{
	char select_task()
	{
		char a = '-';

		std::cout << "Выберите задание из списка: \n"
			"(1) Добавление книги в библиотеку \n"
			"(2) Удаление книги из библиотеку \n"
			"(3) Поиск книги в библиотеке по названию \n"
			"(4) Информация о всех книгах в библиотеке \n" << std::endl;
		std::cin >> a;
		std::cout << std::endl;
		return a;
	}

	TBook::TBook(const std::string& title, const std::string& author, int year) :
		FTitle(title),
		FAuthor(author),
		FYear(year)
	{}
	const std::string& TBook::Title() const { return FTitle; } // гетер(получение доступа), лишнее копирование без ссылки
	const std::string& TBook::Author() const { return FAuthor; }
	int TBook::Year() const { return FYear; } //копия

	TLibrary::TLibrary() :
		FBooks()
	{}

	void TLibrary::addBook(const TBook& book)
	{
		FBooks.push_back(book);
		std::cout << "Книга с названием \"" + book.Title() + "\" была добавлена!" << std::endl;
	}

	void TLibrary::removeBook(const std::string& title)
	{ // Через flag
		bool flag = false;
		for (int i = 0; i < FBooks.size(); ++i)
		{
			if (FBooks[i].Title() == title)
			{
				FBooks.erase(FBooks.begin() + i);
				std::cout << "Книга с названием \"" + title + "\" была удалена!" << std::endl;
				flag = true;
				break;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			std::cout << "Книга с названием \"" + title + "\" отсутствует в библиотеке!" << std::endl; // Поменять
		}
	}

	TBook* TLibrary::findBook(const std::string& title)
	{
		bool flag = true;
		for (int i = 0; i < FBooks.size(); ++i)
		{
			if (FBooks[i].Title() == title)
			{
				std::cout << "Книга с названием \"" + title + "\" найдена!" << std::endl;
				flag = true;
				return &FBooks[i];
				break;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			std::cout << "Книга с названием \"" + title + "\" отсутствует в библиотеке!" << std::endl;
		}
	}

	void TLibrary::printAllBooks()
	{
		if (FBooks.empty())
		{
			std::cout << "Книги в библиотеке отсутствуют!" << std::endl;
		}
		else
		{
			for (int i = 0; i < FBooks.size(); ++i)
			{
				std::cout << "Название книги: \"" + FBooks[i].Title() + "\"" << std::endl;
				std::cout << "Автор книги: \"" + FBooks[i].Author() + "\"" << std::endl;
				std::cout << "Год издания книги: \"" + FBooks[i].Year() << std::endl;
			}
		}
	}

	TLibrary library;

	void task_1()
	{
		std::cout << "Задание 1: Добавление книги в библиотеку" << std::endl;
		std::cout << "Введите название книги: ";
		std::string name;
		std::cin >> name;
		std::cout << "Введите автора книги: ";
		std::string author;
		std::cin >> author;
		std::cout << "Введите год издания книги: ";
		int year = n_ReadInt(INT_MAX);
		if (year == INT_MAX)
			return;
		TBook volume(name, author, year);
		library.addBook(volume);
		std::cout << std::endl;
	}

	void task_2()
	{
		std::cout << "Задание 2: Удаление книги из библиотеку" << std::endl;
		std::cout << "Введите название книги: ";
		std::string name;
		std::cin >> name;
		library.removeBook(name);
		std::cout << std::endl;
	}

	void task_3()
	{
		std::cout << "Задание 3: Поиск книги в библиотеке по названию" << std::endl;
		std::cout << "Введите название книги: ";
		std::string name;
		std::cin >> name;
		library.findBook(name);
		std::cout << std::endl;
	}

	void task_4()
	{
		std::cout << "Задание 4: Информация о всех книгах в библиотеке" << std::endl;
		library.printAllBooks();
		std::cout << std::endl;
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
		//Library::addBook(mybook);
		//Library::printAllBooks();
	}
}