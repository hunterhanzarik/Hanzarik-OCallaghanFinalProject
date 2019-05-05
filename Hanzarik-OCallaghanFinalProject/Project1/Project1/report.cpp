#include <iostream>
#include <iomanip>
#include "reports.h"
using namespace std;
void reports()
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
			repListing();
			break;
		case 2:
			repWholesale();
			break;
		case 3:
			repRetail();
			break;
		case 4:
			repQty();
			break;
		case 5:
			repCost();
			break;
		case 6:
			repAge();
			break;
		default:
			cout << "Back to Main Menu" << endl;
			break;
		}
	} while (choice != 7);
}
void repListing() { cout << "no"; }
void repWholesale() { cout << "no"; }
void repRetail() { cout << "no"; }
void repQty() { cout << "no"; }
void repCost() { cout << "no"; }
void repAge() { cout << "no"; }