#include <string>
using namespace std;

class Book {
private:
	string name, author;		// data members
	int yearOfPublication, ID;


public:
	Book();			 // constructor

	// member functions. Function definition in book.cpp
	void setName(string name_input);
	void setAuthor(string author_input);
	void setYearOfPublication(int yearOfPublication_input);
	void setID(int ID_input);
	void displayBook();
	string getName();
	string getAuthor();
	int getYearOfPublication();
	int getID();
};

#pragma once
