#pragma once
#include<iostream>
using namespace std;

class Author final
{
public:
	Author() = default;
	Author(const string& a_authorName);
	Author(const Author& a_author);
	~Author();

	void setName(const string& a_authorName);
	string getName() const;

	int getAuthorCount();

	virtual void printAuthorInfo() const;

private:
	string m_authorName;
	int m_authorCount = 0;
};

