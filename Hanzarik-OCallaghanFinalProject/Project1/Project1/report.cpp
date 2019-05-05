#include <iostream>
#include <iomanip>
#include "reports.h"
#include "bookinfo.h"
using namespace std;
void reports(bookdata books[], int SIZE)
{
	int choice;
	do {
		cout << setw(50) << "Serendipity Booksellers" << endl;
		cout << setw(40) << "Reports" << endl;
		cout << "1. Inventory Listing" << endl;
		cout << "2. Inventory Wholesale Value" << endl;
		cout << "3. Inventory Retail Value" << endl;
		cout << "4. Listing by Quantity" << endl;
		cout << "5. Listing by Cost" << endl;
		cout << "6. Listing by Age" << endl;
		cout << "7. Return to the Main Menu" << endl;
		cout << "Enter your choice" << endl;

		cin >> choice;

		while (choice < 1 || choice > 7)
		{
			cout << "Invalid Choice. Please pick a number from 1-7" << endl;
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			repListing(books,SIZE);
			break;
		case 2:
			repWholesale(books, SIZE);
			break;
		case 3:
			repRetail(books, SIZE);
			break;
		case 4:
			repQty(books, SIZE);
			break;
		case 5:
			repCost(books, SIZE);
			break;
		case 6:
			repAge(books, SIZE);
			break;
		default:
			cout << "Back to Main Menu" << endl;
			break;
		}
	} while (choice != 7);
}
void repListing(bookdata books[], int SIZE)
{
	cout << setw(40) << "Full Listing" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (!books[i].isEmpty())
		{
			bookinfo(books[i]);
		}
		else
		{
			cout << "There is not book in spot " << i + 1 << endl;
		}
	}
}
void repWholesale(bookdata books[], int SIZE) 
{
	double totalWholesale = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
		cout << "Wholesale Cost: " << books[i].getWholesale() << endl;
		totalWholesale += (books[i].getQty() * books[i].getWholesale());
	}

	cout << "Total Wholesale Cost: " << totalWholesale << endl;
}
void repRetail(bookdata books[], int SIZE) 
{ 
	double totalRetail = 0;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
		cout << "Retail Price: " << books[i].getRetail() << endl;
		totalRetail += (books[i].getQty() * books[i].getWholesale());
	}
	cout << "Total Retail Price: " << totalRetail << endl;
}
void repQty(bookdata books[], int SIZE) { cout << "no"; }
void repCost(bookdata books[], int SIZE) { cout << "no"; }
void repAge(bookdata books[], int SIZE) { cout << "no"; }