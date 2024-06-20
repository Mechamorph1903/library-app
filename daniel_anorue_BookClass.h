#pragma once
#include <string>

using std::string;

class Book
{
public:
	Book();
	Book(string p_title, string p_author, int ISBNno);
	string getTitle();
	string getAuthor();
	int getISBN();
	bool getStatus();
	void setTitle(string new_title);
	void setAuthor(string new_author);
	void setISBN(int new_ISBN);	
	bool checkOutBook(string name);
	void returnBook();
	void outputBook();

private:
	string title;
	string author;
	int ISBN;
	bool status;
	string checkedOutBy;

};

