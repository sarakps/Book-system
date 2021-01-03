#include "BookData.h"
#include "Book.h"
#include "Author.h"
#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>
#include <string>

shared_ptr<BookData> BookData::instance = nullptr;

shared_ptr<BookData> BookData::getInstance()
{
	if (!instance) {
		instance = shared_ptr<BookData>(new BookData());
	}
	return instance;
}

void BookData::addBook(const Book& a_book)
{
	books.push_back(make_shared<Book>(a_book));

	for (auto& f : observers) {
		f(a_book.getTitle());
	}
}

shared_ptr<Book> BookData::searchBook(const string& a_title)
{
	for (shared_ptr<Book>& b : books) {
		if (b->getTitle() == a_title) {
			b->printBookInfo();
			return b;
		}
	}
	cout << "Book '" << a_title << "' not found. " << endl;
	return nullptr;
}

void BookData::sortBooks(const string& a_title)
{
	sort(books.begin(), books.end(), SortBooksByTitle());
}

shared_ptr<Book> BookData::deleteBook(const string& a_title)
{
	int i = 0;
	for (shared_ptr<Book>& b : books) {
		if (b->getTitle() == a_title) {
			i++;
			books.erase(remove(books.begin(), books.end(), b));
			cout << endl << "Book deleted. " << endl;
			break;
		}
	}
	if (i == 0) cout << "Book '" << a_title << "' not found. " << endl;
	return nullptr;
}

shared_ptr<Book> BookData::modifyBook(const string& a_title, const string& new_title, const string& new_author)
{
	int i = 0;
	for (shared_ptr<Book>& b : books) {
		if (b->getTitle() == a_title) {
			string new_title, new_author;
			cout << "New title: ";
			getline(cin, new_title, '\n');
			cout << "New author: ";
			getline(cin, new_author, '\n');
			books.at(i) = make_shared<Book>(new_title, new_author);
			break;
		}
		i++;
	}
	return nullptr;
}

void BookData::printBooks() const
{
	for (const shared_ptr<Book>& b : books) {
		b->printBookInfo();
	}
}

void BookData::addListener(function<void(const string&)> a_observer)
{
	observers.push_back(a_observer);
}
