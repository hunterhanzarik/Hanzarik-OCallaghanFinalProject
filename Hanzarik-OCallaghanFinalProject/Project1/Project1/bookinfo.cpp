#include <iostream>
#include <iomanip>
#include <string>
#include "bookinfo.h"
#include "bookdata.h"
using namespace std;

void bookinfo(bookdata book)
{
	cout << setw(54) << "Serendipity Booksellers" << endl;
	cout << setw(50) << "Book Information" << endl;
	cout << "ISBN: " << book.getIsbn() << endl;
	cout << "Title: " << book.getTitle() << endl;
	cout << "Author: " << book.getAuthor() << endl;
	cout << "Publisher: " << book.getPub() << endl;
	cout << "Date Added: " << book.getDateAdded() << endl;
	cout << "Quantity-On-Hand: " << book.getQty() << endl;
	cout << "Wholesale Cost: " << book.getWholesale() << endl;
	cout << "Retail Price: " << book.getRetail() << endl;
}