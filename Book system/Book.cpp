#include "Book.h"
#include"Author.h"
#include <string>

int Book::m_bookCount{ 0 };

Book::Book(const string& a_title, const Author& a_author) : m_title{ a_title }, m_author{ a_author.getName() } 
{
	m_bookCount++;
	cout << "Book class' constructor with two parameters. " << endl;
}

Book::Book(const Book& a_book) : m_title{a_book.m_title}, m_author{a_book.m_author}
{
	m_bookCount++;
	cout << "Book " << m_title << " data copied. " << endl;
}

Book::~Book()
{
	cout << "Book " << m_title << " destroyed. " << endl;
	m_bookCount--;
}

void Book::setTitle(const string& a_title)
{
	m_title = a_title;
}

void Book::setAuthor(const string& a_author)
{
	m_author = a_author;
}

string Book::getAuthor() const
{
	return m_author;
}

string Book::getTitle() const
{
	return m_title;
}

int Book::getBookCount()
{
	return m_bookCount;
}

void Book::printBookInfo() const
{
	cout << "Title: '" << getTitle()
		<< "', Author: '" << getAuthor() << "' " << endl;

}
