#include "Author.h"
#include "Book.h"
#include "BookData.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	auto bookData = BookData::getInstance();
	char action;
	string title, new_title, author, new_author;
	Book bookobject;
	Author authorObject;

	auto bookdataListener = [](const string& a_title) {
		cout << "Lambda listener has noticed '" << a_title << "' was added. " << endl;
	};

	bookData->addListener(bookdataListener);

	do
	{
		cout << endl << "==========================" << endl
			<< "---------- Menu ----------" << endl
			<< "==========================" << endl
			<< "Choose an action" << endl
			<< "(A) Add a book " << endl
			<< "(D) Delete a book " << endl
			<< "(M) Modify a book " << endl
			<< "(F) Search for a book " << endl
			<< "(S) Sort all the books " << endl
			<< "(P) Print all the books " << endl
			<< "(E) Exit program " << endl 
			<< "==========================" << endl << endl << flush;
		cin >> action;
		cin.ignore();
		switch (toupper(action))
		{
		case 'A':
			//add a book
			cout << "Title: ";
			getline(cin, title, '\n');
			cout << "Author: ";
			getline(cin, author, '\n');
			bookData->addBook(Book{ title, author });
			cout << endl << "Book added. " << endl;
			break;
		case 'D':
			//delete a book
			cout << "Title: ";
			getline(cin, title, '\n');
			bookData->deleteBook(title);
			break;
		case 'F':
			//search a book
			cout << "Title: ";
			getline(cin, title, '\n');
			bookData->searchBook(title);
			break; 
		case 'M':
			//modify a book
			cout << "Title: ";
			getline(cin, title, '\n');
			bookData->modifyBook(title, new_title, new_author);
			cout << endl << "Book modified. " << endl;
			break;
		case 'S':
			//sort books-vector by title
			bookData->sortBooks(title);
			cout << endl << "Books sorted. " << endl;
			break;
		case 'P':
			//print books-vector
			bookData->printBooks();
			break;
		case 'E':
			cout << "Exited " << endl;
			break;
		default:
			cout << "Invalid option. Try again. " << endl;
		}
	} while (toupper(action) != 'E');

	return EXIT_SUCCESS;
}

