//Serendipity Booksellers
//Hunter Hanzarik & Chris O'Callaghan

#include <iostream>
#include <iomanip>
#include "bookinfo.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "bookdata.h"

const int NUM = 20;

using namespace std;
int main()
{
	bookdata books[NUM];

	for (int i = 0; i < NUM; i++)
	{
		books[i] = bookdata();
	}

	int choice;
	do {
		cout << setw(69) << "Serendipity Booksellers" << endl;
		cout << setw(62) << "Main Menu" << endl;
		cout << "1. Cashier Module" << endl;
		cout << "2. Inventory Database Module" << endl;
		cout << "3. Report Module" << endl;
		cout << "4. Exit" << endl << endl;
		cout << "Enter your choice " << endl;

		cin >> choice;
		while (choice < 1 || choice > 4) {
			cout << "Invalid Choice. Please pick a number from 1-4" << endl;
			cin >> choice;
		}
		cin.ignore();
		switch (choice) {
		case 1:
			cashier(books);
			break;
		case 2:
			invmenu(books, NUM);
			break;
		case 3:
			reports(books,NUM);
			break;
		default:
			cout << "Goodbye" << endl;
			break;
		}
	} while (choice != 4);
	return 0;
}