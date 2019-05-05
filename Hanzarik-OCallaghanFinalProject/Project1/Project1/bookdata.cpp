#include "bookdata.h"

bookdata::bookdata()
{
	bookTitle = "";
	isbn = "";
	author = "";
	publisher = "";
	dateAdded = "";
	qtyOnHand = 0;
	wholesale = 0;
	retail = 0;
	removeBook();
}

bookdata::~bookdata()
{
	bookTitle = "";
	isbn = "";
	author = "";
	publisher = "";
	dateAdded = "";
	qtyOnHand = 0;
	wholesale = 0;
	retail = 0;
	removeBook();
}


// Setters/Mutators
void bookdata::setTitle(string s)
{
	bookTitle = s;
}
void bookdata::setIsbn(string s)
{
	isbn = s;
}
void bookdata::setAuthor(string s)
{
	author = s;
}
void bookdata::setPub(string s)
{
	publisher = s;
}
void bookdata::setDateAdded(string s)
{
	dateAdded = s;
}
void bookdata::setQty(int s)
{
	qtyOnHand = s;
}
void bookdata::setWholesale(double s)
{
	wholesale = s;
}
void bookdata::setRetail(double s)
{
	retail = s;
}
void bookdata::insertBook()
{
	empty = false;
}
void bookdata::removeBook()
{
	empty = true;
}

// Getters/Accessors
string bookdata::getTitle()
{
	return bookTitle;
}
string bookdata::getIsbn()
{
	return isbn;
}
string bookdata::getAuthor()
{
	return author;
}
string bookdata::getPub()
{
	return publisher;
}
string bookdata::getDateAdded()
{
	return dateAdded;
}
int bookdata::getQty()
{
	return qtyOnHand;
}
double bookdata::getWholesale()
{
	return wholesale;
}
double bookdata::getRetail()
{
	return retail;
}
bool bookdata::isEmpty()
{
	return empty;
}