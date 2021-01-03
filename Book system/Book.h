#pragma once
#include"Author.h"
#include <iostream>
#include <memory>
using namespace std;


class Book
{
public:
	Book() = default;
	Book(const string& a_title, const Author& a_author); 
	Book(const Book& a_book);
	~Book(); 

	void setTitle(const string& a_title);
	void setAuthor(const string& a_authorName);
	
	string getTitle() const;
	string getAuthor() const;

	int getBookCount();

	virtual void printBookInfo() const;

	int operator==(const Book& a_book) const {
		return getTitle() == a_book.getTitle() && getAuthor() == a_book.getAuthor();
	}


private:
	string m_title;
	string m_author;
	static int m_bookCount;
};
