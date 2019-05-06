#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <string>

using namespace std;

class bookdata {
private:
	string bookTitle, isbn, author, publisher, dateAdded;
	int qtyOnHand;
	double wholesale, retail;
	bool empty;

public:
	// Constructor(s)
	bookdata();
	// Destructor
	~bookdata();

	// Setters/Mutators
	void setTitle(string s);
	void setIsbn(string s);
	void setAuthor(string s);
	void setPub(string s);
	void setDateAdded(string s);
	void setQty(int s);
	void setWholesale(double s);
	void setRetail(double s);
	void insertBook();
	void removeBook();

	// Getters/Accessors
	string getTitle();
	string getIsbn();
	string getAuthor();
	string getPub();
	string getDateAdded();
	int getQty();
	double getWholesale();
	double getRetail();
	bool isEmpty();


};

#endif

