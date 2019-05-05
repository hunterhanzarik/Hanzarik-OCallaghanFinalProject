#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "cashier.h"
#include "invmenu.h"
#include "bookdata.h"
using namespace std;

const int SIZE = 20;
const double salesTax = 0.06;

void cashier(bookdata books[])
{
	bookdata toBuy[SIZE];
	int quantity[SIZE], index, tbIndex = 0;
	string isbn, date;
	double total[SIZE], tax, totalPlusTax,finalTotal = 0;
	
	char cont;
	cout << "Please enter today's date" << endl;
	getline(cin, date);

	do {
		cout << "Please enter the 13 digit ISBN number or Title of the book being purchased" << endl;
		getline(cin, isbn);

		index = findBook(books, SIZE, isbn);

		if (index > -1 && !books[index].isEmpty())
		{
			cout << "Serendipity Booksellers" << endl;
			cout << "Cashier Module" << endl << endl;
			cout << "Date: " << date << endl;
			cout << "Quantity of book: " << books[index].getQty() << endl;
			cout << "ISBN: " << books[index].getIsbn() << endl;
			cout << "Title: " << books[index].getTitle() << endl;
			cout << "Price: $" << books[index].getRetail() << endl;

			cout << "How many would you like to buy? ";
			cin >> quantity[tbIndex];
			cin.ignore();

			if (quantity[tbIndex] <= books[index].getQty())
			{
				books[index].setQty((books[index].getQty() - quantity[tbIndex]));
				toBuy[tbIndex] = books[index];

				total[tbIndex] = quantity[tbIndex] * books[index].getRetail();

				tbIndex++;
			}
			else
				return;
		}
		else
			cout << "That book could not be found.";

		cout << endl << "Would you like to continue? Y or N : ";
		cin >> cont;

	} while (toupper(cont) == 'Y');
		// search for the title and the price cooresponding with ISBN using the array

	for (int i = 0; i < tbIndex; i++)
	{
		finalTotal += total[i];
	}
	tax = finalTotal * salesTax;
	totalPlusTax = tax + finalTotal;

	cout << setw(5)<< left << "Qty" << setw(15) << left << "ISBN" << setw(42) << left <<"Title" << setw(8) << left << "Price" << setw(8) << left << "Total" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < tbIndex; i++)
	{
		cout << setw(5) << left << quantity[i] << setw(15) << left << toBuy[i].getIsbn() << setw(42) << left << toBuy[i].getTitle() << 
			setprecision(2) << fixed << showpoint << setw(8) << left << toBuy[i].getRetail() << setw(8) << left << total[i] << endl;
	}
	cout << setw(25) << "Subtotal" << setw(45) << finalTotal << endl;
	cout << setw(25) << "Tax" << setw(45) << tax << endl;
	cout << setw(25) << "Total" << setw(45) << totalPlusTax;
}