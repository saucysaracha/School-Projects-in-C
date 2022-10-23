// CSE240 Fall 2022 HW9
// Sara Schultz
// Write the compiler used: Visual studio

#include "book.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Book (2 points)
// Book() constructor assigns the following default values to class data members
// name: abc
// author: bcd
// yearOfPublication: 2000
// ID: 0
Book::Book()
{
	// Write the code below
	name = "abc";
	author = "bcd";
	yearOfPublication = 2000;
	ID = 0;

}

// Q2 (18 points)
// 2 points for each function

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Book' object which will represent one book.
// Eg-  Book b[10]; creates 10 Book objects
//		b[2].setID(19); will set 3rd book's ID to 19

// setName assigns 'name_input' to class data member 'name'
void Book::setName(string name_input)
{
	// Write the code below
	name = name_input;
}

// setAuthor assigns author_input to class data member 'author'
void Book::setAuthor(string author_input)
{
	// Write the code below
	author = author_input;
}

// setYearOfPublication assigns 'yearOfPublication_input' to class data member 'yearOfPublication'
void Book::setYearOfPublication(int yearOfPublication_input)
{
	// Write the code below
	yearOfPublication = yearOfPublication_input;
}

// setID assigns 'ID_input' to class data member 'ID'
void Book::setID(int ID_input)
{
	// Write the code below
	ID = ID_input;
}

// displayBook displays the name, author, Publication Year and ID of the book
// See expected output in question file.
void Book::displayBook()
{
	// Write the code below
	cout << "Name: " << name << endl;
	cout << "Name of Book Author: " << author << endl;
	cout << "Publication Year: " << yearOfPublication << endl;
	cout << "ID: " << ID << endl;
	cout << "\n";

}

// getName returns the class data member 'name'.
string Book::getName()
{
	// Write the code below
	return name;
}

// getAuthor returns the class data member 'author'.
string Book::getAuthor()
{
	// Write the code below
	return author;
}

// getYearOfPublication returns the class data member 'yearOfPublication'.
int Book::getYearOfPublication()
{
	// Write the code below
	return yearOfPublication;
}

// getID returns the class data member 'ID'.
int Book::getID()
{
	// Write the code below
	return ID;
}