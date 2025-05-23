#include "lab_12.h"


namespace lab_12
{
	char select_task()
	{
		char a = '-';

		std::cout << "�������� ������� �� ������: \n"
			"(1) ���������� ����� � ���������� \n"
			"(2) �������� ����� �� ���������� \n"
			"(3) ����� ����� � ���������� �� �������� \n"
			"(4) ���������� � ���� ������ � ���������� \n" << std::endl;
		std::cin >> a; 
		std::cout << std::endl;
		return a;
	}

	TBook::TBook(const std::string& title, const std::string& author, int year) :
		FTitle(title),
		FAuthor(author),
		FYear(year)
	{}
	const std::string& TBook::Title() const { return FTitle; } // �����(��������� �������), ������ ����������� ��� ������
	const std::string& TBook::Author() const { return FAuthor; }
	int TBook::Year() const { return FYear; } //�����

	TLibrary::TLibrary() :
		FBooks()
	{}

	void TLibrary::addBook(const TBook& book)
	{
		FBooks.push_back(book);
		std::cout << "����� � ��������� \"" + book.Title() + "\" ���� ���������!" << std::endl;
	}

	void TLibrary::removeBook(const std::string& title)
	{ // ����� flag
		bool flag = false;
		for (int i = 0; i < FBooks.size(); ++i)
		{
			if (FBooks[i].Title() == title)
			{
				FBooks.erase(FBooks.begin() + i);
				std::cout << "����� � ��������� \"" + title + "\" ���� �������!" << std::endl;
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
			std::cout << "����� � ��������� \"" + title + "\" ����������� � ����������!" << std::endl; // ��������
		}
	}

	TBook* TLibrary::findBook(const std::string& title)
	{
		bool flag = true;
		for (int i = 0; i < FBooks.size(); ++i)
		{
			if (FBooks[i].Title() == title)
			{
				std::cout << "����� � ��������� \"" + title + "\" �������!" << std::endl;
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
			std::cout << "����� � ��������� \"" + title + "\" ����������� � ����������!" << std::endl;
		}
	}

	void TLibrary::printAllBooks()
	{
		if (FBooks.empty())
		{
			std::cout << "����� � ���������� �����������!" << std::endl;
		}
		else
		{
			for (int i = 0; i < FBooks.size(); ++i)
			{
				std::cout << "�������� �����: \"" + FBooks[i].Title() + "\"" << std::endl;
				std::cout << "����� �����: \"" + FBooks[i].Author() + "\"" << std::endl;
				std::cout << "��� ������� �����: \"" + FBooks[i].Year() << std::endl;
			}
		}
	}

	TLibrary library;

	void task_1()
	{
		std::cout << "������� 1: ���������� ����� � ����������" << std::endl;
		std::cout << "������� �������� �����: ";
		std::string name;
		std::cin >> name;
		std::cout << "������� ������ �����: ";
		std::string author;
		std::cin >> author;
		std::cout << "������� ��� ������� �����: ";
		int year = n_ReadInt(INT_MAX);
		if (year == INT_MAX)
			return;
		TBook volume(name, author, year);
		library.addBook(volume);
		std::cout << std::endl;
	}

	void task_2()
	{
		std::cout << "������� 2: �������� ����� �� ����������" << std::endl;
		std::cout << "������� �������� �����: ";
		std::string name;
		std::cin >> name;
		library.removeBook(name);
		std::cout << std::endl;
	}

	void task_3()
	{
		std::cout << "������� 3: ����� ����� � ���������� �� ��������" << std::endl;
		std::cout << "������� �������� �����: ";
		std::string name;
		std::cin >> name;
		library.findBook(name);
		std::cout << std::endl;
	}

	void task_4()
	{
		std::cout << "������� 4: ���������� � ���� ������ � ����������" << std::endl;
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
			case '0': std::cout << "����� �� ���������" << std::endl; break;
			default: std::cout << "������������ ����, ���������� �����" << std::endl;
			}
		}
		//Library::addBook(mybook);
		//Library::printAllBooks();
	}
}