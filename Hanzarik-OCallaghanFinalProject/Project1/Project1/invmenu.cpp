#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "cashier.h"
#include "bookdata.h"
#include "bookinfo.h"	
#include "invmenu.h"

using namespace std;
const int SIZE = 20;

void invmenu(bookdata books[], int SIZE)
{
	int choice;
	do {
		cout << setw(54) << "Serendipity Booksellers" << endl;
		cout << setw(50) << "Inventory Database" << endl;
		cout << "1. Look-Up a Book" << endl;
		cout << "2. Add a Book" << endl;
		cout << "3. Edit a Book's Record" << endl;
		cout << "4. Delete a Book" << endl;
		cout << "5. Return to the Main Menu" << endl << endl;
		cout << "Enter your choice" << endl;

		cin >> choice;

		while (choice < 1 || choice > 5)
		{
			cout << "Invalid Choice. Please pick a number from 1-5" << endl;
			cin >> choice;
		}

		cin.ignore();
		switch (choice) {
		case 1:
			lookUpBook(books, SIZE);
			break;
		case 2:
			addBook(books, SIZE);
			break;
		case 3:
			editBook(books, SIZE);
			break;
		case 4:
			deleteBook(books, SIZE);
		default:
			cout << "Back to Main Menu" << endl;
			break;
		}
	} while (choice != 5);

}
void lookUpBook(bookdata books[], int SIZE) {
	string search;
	int index = 0;
	cout << "What book do you want to look up? (Title or ISBN)" << endl;
	getline(cin, search);
	index = findBook(books, SIZE, search);
	if (index > -1)
		bookinfo(books[index]);
	else
		cout << "Book could not be found.\n";
}

void addBook(bookdata books[], int SIZE) {
	string stemp;
	char cstemp[14];
	double dtemp;
	int itemp, index;
	bool flagg;

	for (int i = 0; i < SIZE; i++)
	{
		if (books[i].isEmpty())
		{
			index = i;
			break;
		}
		else if (i == SIZE - 1)
			return;
	}
	if (index == 19)
	{
		cout << "No more books can be added.\n";
	}
	else {
		cout << "Please enter the data for book " << index + 1;
		cout << "\nBook Title: ";
		do {
			getline(cin, stemp);
			if (stemp.compare("") == 0)
				cout << "Please enter a valid book title\n";
		} while (stemp.compare("") == 0);
		books[index].setTitle(stemp);

		cout << "\n13 Digit ISBN: ";
		do {
			flagg = true;
			cin.getline(cstemp, 14);
			for (int i = 0; i < 13; i++)
			{
				if (!isdigit(cstemp[i]))
					flagg = false;
			}
			if (flagg == false)
				cout << "Please enter a valid ISBN\n";
		} while (flagg == false);
		books[index].setIsbn(cstemp);

		cout << "\nAuthor: ";
		do {
			getline(cin, stemp);
			if (stemp.compare("") == 0)
				cout << "Please enter a valid author\n";
		} while (stemp.compare("") == 0);
		books[index].setAuthor(stemp);

		cout << "\nPublisher: ";
		do {
			getline(cin, stemp);
			if (stemp.compare("") == 0)
				cout << "Please enter a valid publisher\n";
		} while (stemp.compare("") == 0);
		books[index].setPub(stemp);

		cout << "\nDate Added (MM-DD-YYYY): ";
		do {
			flagg = false;
			cin.getline(cstemp, 11);

			for (int i = 0; i < 10; i++)
			{
				if (isdigit(cstemp[i]))
					flagg = true;
				else if (cstemp[i] == '-' && (i == 2 || i == 5))
					flagg = true;
				else
				{
					flagg = false;
					break;
				}
			}

			if (flagg == false)
				cout << "Please enter a valid date. (MM-DD-YYYY)";

		} while (flagg == false);
		books[index].setDateAdded(cstemp);

		cout << "\nQuantity: ";
		do {
			cin >> itemp;
			if (itemp < 0)
				cout << "Please enter a valid quantity\n";
		} while (itemp < 0);
		books[index].setQty(itemp);

		cout << "\nWholesale Price: $";
		do {
			cin >> dtemp;
			if (dtemp < 0)
				cout << "Please enter a valid price\n";
		} while (dtemp < 0);
		books[index].setWholesale(dtemp);

		cout << "\nRetail Price: $";
		do {
			cin >> dtemp;
			if (dtemp < 0)
				cout << "Please enter a valid price\n";
		} while (dtemp < 0);
		books[index].setRetail(dtemp);

		books[index].insertBook();

		cin.ignore();
	}
}

void editBook(bookdata books[], int SIZE) {
	string stemp;
	char cstemp[14];
	double dtemp;
	int itemp, bookNum, userChoice;
	bool flagg;

	cout << "What book do you want to look up? (Title or ISBN)" << endl;
	getline(cin, stemp);
	bookNum = findBook(books, SIZE, stemp);
	if (bookNum > -1) {
		cout << "1. Title\n2. ISBN\n3. Author\n4. Publisher\n5. Date Added\n6. Quantity\n7. Wholesale Cost\n8. Retail Price\n";
		cout << "Which info would you like to edit? ";
		do{cin >> userChoice;
		if (userChoice < 1 || userChoice > 8)
		cout << "Invalid Choice\n";
		}while(userChoice < 1 || userChoice > 8);

		cin.ignore();

		cout << "Please enter the data for book " << bookNum + 1;
		switch(userChoice)
		{
		case 1:
			cout << "\nBook Title: ";
			do {
				cin >> stemp;
				if (stemp.compare("") == 0)
					cout << "Please enter a valid book title\n";
			} while (stemp.compare("") == 0);
			books[bookNum].setTitle(stemp);
			break;

		case 2:
			cout << "\n13 Digit ISBN: ";
			do {
				flagg = true;
				cin.getline(cstemp, 14);
				for (int i = 0; i < 13; i++)
				{
					if (!isdigit(cstemp[i]))
						flagg = false;
				}
				if (flagg == false)
					cout << "Please enter a valid ISBN\n";
			} while (flagg == false);
			books[bookNum].setIsbn(cstemp);
			break;

		case 3:
			cout << "\nAuthor: ";
			do {
				cin >> stemp;
				if (stemp.compare("") == 0)
					cout << "Please enter a valid author\n";
			} while (stemp.compare("") == 0);
			books[bookNum].setAuthor(stemp);
			break;

		case 4:
			cout << "\nPublisher: ";
			do {
				cin >> stemp;
				if (stemp.compare("") == 0)
					cout << "Please enter a valid publisher\n";
			} while (stemp.compare("") == 0);
			books[bookNum].setPub(stemp);
			break;

		case 5:
			cout << "\nDate Added (MM-DD-YYYY): ";
			do {
				flagg = false;
				cin.getline(cstemp, 11);

				for (int i = 0; i < 10; i++)
				{
					if (isdigit(cstemp[i]))
						flagg = true;
					else if (cstemp[i] == '-' && (i == 2 || i == 5))
						flagg = true;
					else
					{
						flagg = false;
						break;
					}
				}

				if (flagg == false)
					cout << "Please enter a valid date. (MM-DD-YYYY)";

			} while (flagg == false);
			books[bookNum].setDateAdded(cstemp);
			break;
			
		case 6:
			cout << "\nQuantity: ";
			do {
				cin >> itemp;
				if (itemp < 0)
					cout << "Please enter a valid quantity\n";
			} while (itemp < 0);
			books[bookNum].setQty(itemp);
			break;

		case 7:
			cout << "\nWholesale Price: $";
			do {
				cin >> dtemp;
				if (dtemp < 0)
					cout << "Please enter a valid price\n";
			} while (dtemp < 0);
			books[bookNum].setWholesale(dtemp);
			break;

		case 8:
			cout << "\nRetail Price: $";
			do {
				cin >> dtemp;
				if (dtemp < 0)
					cout << "Please enter a valid price\n";
			} while (dtemp < 0);
			books[bookNum].setRetail(dtemp);
			break;
		}
	}
	else
		cout << "The book was not found.";

	cin.ignore();
}

void deleteBook(bookdata books[], int SIZE){
	int bookNum;
	string search;

	
	cout << "Enter the book that you would like to remove." << endl;
	cin.ignore();
	getline(cin, search);
	bookNum = findBook(books,SIZE,search);
	if (bookNum > -1)
	{
		char delet;
		bookinfo(books[bookNum]);

		cout << "Would you like to remove this book? Y or N\n";
		cin >> delet;

		if(toupper(delet) == 'Y')
			books[bookNum].~bookdata();

	}
	else
		cout << "That book was not found.";
}

int findBook(bookdata books[], int SIZE, string s){
	for (int i = 0; i < SIZE; i++)
	{
		if (books[i].getTitle().compare(s) == 0)
		{

			return i;
		}
		else if (books[i].getIsbn().compare(s) == 0)
		{

			return i;
		}
	}
	return -1;
}