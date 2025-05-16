#pragma once
//для внешнего использования
#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "../my_lib.h"

namespace lab_12
{
	void menu();

	class TBook {
	private:
		std::string FTitle; //префикс
		std::string FAuthor;
		int         FYear;
	public:
		TBook(const std::string& title, const std::string& author, int year);
		const std::string& Title() const;
		const std::string& Author() const;
		int Year() const;
	};

	class TLibrary {
	private:
		std::vector<TBook> FBooks;
	public:
		TLibrary();
		void addBook(const TBook& book);
		void removeBook(const std::string& title);
		TBook* findBook(const std::string& title);
		void printAllBooks();
	};
}


