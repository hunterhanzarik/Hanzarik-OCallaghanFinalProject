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

		cin.ignore();
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
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "Title: " << books[i].getTitle() << endl;
			cout << "Author: " << books[i].getAuthor() << endl;
			cout << "Publisher: " << books[i].getPub() << endl;
			cout << "Date Added: " << books[i].getDateAdded() << endl;
			cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
			cout << "Wholesale Cost: " << books[i].getWholesale() << endl;
			cout << "Retail Price: " << books[i].getRetail() << endl;
		}
		else
			cout << "There is not a book in spot " << i + 1 << endl;
	}
}

void repWholesale(bookdata books[], int SIZE) 
{
	double totalWholesale = 0;
	cout << setw(40) << "Wholesale Listing" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!books[i].isEmpty())
		{
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "Title: " << books[i].getTitle() << endl;
			cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
			cout << "Wholesale Cost: " << books[i].getWholesale() << endl;
			totalWholesale += (books[i].getQty() * books[i].getWholesale());
		}
		else
			cout << "There is not a book in spot " << i + 1 << endl;
	}
	cout << "Total Wholesale Cost: " << totalWholesale << endl;
}

void repRetail(bookdata books[], int SIZE) 
{ 
	double totalRetail = 0;
	cout << setw(40) << "Retail Listing" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!books[i].isEmpty())
		{
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "Title: " << books[i].getTitle() << endl;
			cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
			cout << "Retail Price: " << books[i].getRetail() << endl;
			totalRetail += (books[i].getQty() * books[i].getRetail());
		}
		else
		{
			cout << "There is not a book in spot " << i + 1 << endl;
		}
	}
	cout << "Total Retail Price: " << totalRetail << endl;
}

void repQty(bookdata books[], int SIZE) 
{
	bool swap;
	bookdata temp;
	int bottom = SIZE - 1;   
								
	do
	{
		swap = false;
		for (int count = 0; count < bottom; count++)
		{
			if (books[count].getQty() < books[count + 1].getQty())
			{	     
				temp = books[count];
				books[count] = books[count + 1];
				books[count + 1] = temp;
				swap = true; 
			}
		}
		bottom--;  

	} while (swap != false); //Sort

	cout << setw(40) << "Quantity Listing" << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		if (!books[i].isEmpty())
		{
			cout << "ISBN: " << books[i].getIsbn() << endl;
			cout << "Title: " << books[i].getTitle() << endl;
			cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
		}
		else
		{
			cout << "There is not a book in spot " << i + 1 << endl;
		}
	}
}

void repCost(bookdata books[], int SIZE) 
{
	bool swap;
	bookdata temp;
	int bottom = SIZE - 1;    

	do
	{
		swap = false;
		for (int count = 0; count < bottom; count++)
		{
			if (books[count].getWholesale() < books[count + 1].getWholesale())
			{	           
				temp = books[count];
				books[count] = books[count + 1];
				books[count + 1] = temp;
				swap = true;
			}
		}
		bottom--;

	} while (swap != false); //Sort
	
	cout << setw(40) << "Wholesale Listing" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!books[i].isEmpty())
		{
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
		cout << "Retail Price: " << books[i].getRetail() << endl;
		}
		else
		{
			cout << "There is not a book in spot " << i + 1 << endl;
		}
	}
}

void repAge(bookdata books[], int SIZE)
{ 
	bool swap;
	bookdata temp;
	int y1, y2, m1, m2, d1, d2, bottom = SIZE - 1;

	do
	{
		swap = false;
		for (int count = 0; count < bottom; count++)
		{
			if (books[count].getDateAdded().compare("") != 0 && books[count+1].getDateAdded().compare("") != 0)
			{
				y1 = stoi(books[count].getDateAdded().substr(6, 4));
				y2 = stoi(books[count + 1].getDateAdded().substr(6, 4));
				m1 = stoi(books[count].getDateAdded().substr(0, 2));
				m2 = stoi(books[count + 1].getDateAdded().substr(0, 2));
				d1 = stoi(books[count].getDateAdded().substr(3, 2));
				d2 = stoi(books[count + 1].getDateAdded().substr(3, 2));

				if (y1 < y2)
				{
					temp = books[count];
					books[count] = books[count + 1];
					books[count + 1] = temp;
					swap = true;
				}

				else if (y1 == y2 && m1 < m2)
				{
					temp = books[count];
					books[count] = books[count + 1];
					books[count + 1] = temp;
					swap = true;
				}

				else if (y1 == y2 && m1 == m2 && d1 < d2)
				{
					temp = books[count];
					books[count] = books[count + 1];
					books[count + 1] = temp;
					swap = true;
				}
			}
		}
		bottom--;

	} while (swap != false); //Sort

	cout << setw(40) << "Date Listing" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if(!books[i].isEmpty())
		{
		cout << "ISBN: " << books[i].getIsbn() << endl;
		cout << "Title: " << books[i].getTitle() << endl;
		cout << "Quantity-On-Hand: " << books[i].getQty() << endl;
		cout << "Date Added: " << books[i].getDateAdded() << endl;
		}
		else
			cout << "There is not a book in spot " << i + 1 << endl;
	}
}