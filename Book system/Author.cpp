#include "Author.h"
#include <string>


Author::Author(const string& a_authorName) : m_authorName{a_authorName}
{
    m_authorCount++;
    cout << "Author class' constructor with one parameter. " << endl;
}

Author::Author(const Author& a_author) : m_authorName{a_author.m_authorName}
{
    m_authorCount++;
    cout << "Author " << m_authorName << " data copied. " << endl;
}

Author::~Author()
{
    cout << "Author " << m_authorName << " deleted. " << endl;
    m_authorCount--;
}

void Author::setName(const string& a_authorName)
{
    m_authorName = a_authorName;
}

string Author::getName() const
{
    return m_authorName;
}

int Author::getAuthorCount()
{
    return m_authorCount;
}

void Author::printAuthorInfo() const
{
    cout << "Name: " << m_authorName << endl;
}
