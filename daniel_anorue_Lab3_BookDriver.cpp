/*
Name: Daniel ANorue
NetID: w10166216

Program Description: a program that stores information about , Checks out and returns books in a library.

//Note: Change this name to reflect submission instrucions
*/
#include "daniel_anorue_BookClass.h"
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::getline;
using std::endl;


void populateBookArray(Book library[]);
int lookupByISBN(Book library[]);

const int SIZE = 5;

int main()
{
	//Create an array of Book objects to store our library in.
	Book library[SIZE];

	//Populate our library with sample books.
	populateBookArray(library);

	int user_input = -1;

	while (user_input != 4)
	{

		cout << "Menu:" << endl;
		cout << "\t 1. Search a Book by ISBN" << endl;
		cout << "\t 2. Check Out a Book" << endl;
		cout << "\t 3. Return a Book." << endl;
		cout << "\t 4. Quit Program." << endl;
		cout << endl;
		cout << "Choose an option: ";
		cin >> user_input;
		cout << endl;

		if (user_input == 1)
		{
			int result;

			result = lookupByISBN(library);
			cout << endl;

			if (result != -1) {
				library[result].outputBook();
				cout << endl;
			}
			else
			{
				cout << "ERROR: " << endl;
				cout << "Book not found. XO" << endl;
				cout << endl;
			}

		} 
		else if (user_input == 2)
		{
			int result;
			result = lookupByISBN(library);
			cout << endl;

			if (library[result].getStatus() == false)
			{
				string name;
				cout << "Who is checking the book out? ";
				cin >> name;

				library[result].checkOutBook(name);

				cout << "Successfully Checked Out! ;)" << endl;
				cout << endl;
			}	
			else
			{
				cout << "Uh Oh! This book has already been checked out :(" << endl;
				cout << endl;
			}
		}
		else if (user_input == 3)
		{
			int result;

			result = lookupByISBN(library);
			cout << endl;

			if (library[result].getStatus() != false)
			{
				library[result].returnBook();
				cout << "Book returned succesfully! B)" << endl;
				cout << endl;
			}
			else
			{
				cout << "This book hasn't been checked out. :|" << endl;
				cout << endl;
			}
		}
		else if (user_input !=4)
		{
			cout << "Not an Option on the Menu. Please Pick Again. B(" << endl;
			cout << endl;
		}

		
	};
	cout << "Have a Nice Day! XD" << endl;
	cout << endl;
	return 0;
}

//Note: This function assumes that there are 5 elements in this array.
//Function populates our library with popular novels.   
//ISBN numbers are just random 5 digit numbers.
//You can assume for the rest of your functions that the library
//array is always 5 elements.
void populateBookArray(Book library[])
{
	library[0].setAuthor("JK Rowling");
	library[0].setTitle("Harry Potter and the Sorcerers Stone");
	library[0].setISBN(98346);

	library[1].setAuthor("C.S. Lewis");
	library[1].setTitle("The Lion, the Witch, and the Wardrobe");
	library[1].setISBN(45336);

	library[2].setAuthor("E. B. White");
	library[2].setTitle("Charlotte's Web");
	library[2].setISBN(56432);

	library[3].setAuthor("F. Scott Fitzgerald");
	library[3].setTitle("The Great Gasby");
	library[3].setISBN(11934);

	library[4].setAuthor("S. E. Hinton");
	library[4].setTitle("The Outsiders");
	library[4].setISBN(72331);
}


//Asks the user for the ISBN number of the book
//and searches the library for that book.
//If found, returns the book element's index
//if not found, returns -1.
int lookupByISBN(Book library[])
{
	int ISBN;

	cout << "Enter the ISBN: ";
	cin >> ISBN;

	for (int i = 0; i < SIZE; i++)
	{
		if (ISBN == library[i].getISBN())
			return i;
	}

	return -1;
}