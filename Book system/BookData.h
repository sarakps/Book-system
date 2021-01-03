#pragma once
#include "Book.h"
#include <iostream>
#include <functional>
#include <vector>
using namespace std;


class BookObserver final {
public:
	virtual void BookAdded(const string& a_title) = 0;
	virtual void BookDeleted(const string& a_title) = 0;
};


class BookData final
{
public:
	BookData() = default;
	static shared_ptr<BookData> getInstance();

	void addBook(const Book& a_title);
	shared_ptr<Book> searchBook(const string& a_title);
	void sortBooks(const string& a_title);
	shared_ptr<Book> deleteBook(const string& a_title);
	shared_ptr<Book> modifyBook(const string& a_title, const string& new_title, const string& new_author);
	void printBooks() const;

	void addListener(function<void(const string&)> a_observer);

private:
	static shared_ptr<BookData> instance;
	vector<function<void(const string&)>> observers;
	vector<shared_ptr<Book>> books;
	vector<shared_ptr<Author>> authors;
	BookData(const BookData& a_bookData) = delete; 
};

class SortBooksByTitle {
public:
	bool operator()(shared_ptr<Book>& b1, shared_ptr<Book>& b2) {
		return b1->getTitle() < b2->getTitle();
	}
};
