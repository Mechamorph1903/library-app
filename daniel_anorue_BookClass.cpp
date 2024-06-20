#include "daniel_anorue_BookClass.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book()
{
	title = "";
	author = "";
	ISBN = 12345;
	status = false;
	checkedOutBy = "";
}

Book::Book(string p_title, string p_author, int ISBNno ) {
	title = p_title;
	author = p_author;
	ISBN = ISBNno;
	status = false;
	checkedOutBy = "";
}

string Book::getTitle()
{
	return title;
}

string Book::getAuthor()
{
	return author;
}

int Book::getISBN() 
{
	return ISBN;
}

bool Book::getStatus()
{
	return status;
}

void Book::setTitle(string new_title)
{
	 title = new_title;
}

void Book::setAuthor(string new_author)
{
	author = new_author;
}

void Book::setISBN(int new_ISBN)
{
	ISBN = new_ISBN;
}

bool Book::checkOutBook(string name)
{
	if (status != true) {
		status = true;
		checkedOutBy = name;
		return true;
	}
	else {
		return false;
	}
	
}

void Book::returnBook()
{
	status = false;
	checkedOutBy = "";

}

void Book::outputBook()
{
	if (status == true) 
	{
		cout << title << endl;
		cout << "\t by " << author << endl;
		cout << "\t ISBN: " << ISBN << endl;
		cout << "\t Checked out by: " << checkedOutBy << endl;
	}
	else
	{
		cout << title << endl;
		cout << "\t by " << author << endl;
		cout << "\t ISBN: " << ISBN << endl;
	}


}