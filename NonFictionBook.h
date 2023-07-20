#pragma once
#include "Book.h"

class NonFictionBook : public Book {
public:
	// Default Constructor
	NonFictionBook();

	// Constructor. Initializes the BookstoreManger object.
	// Params:
	// - title: The title to satisfy Book constructor title_
	// - author: The author to satisfy Book constructor author_
	// - price: The price to satisfy Book constructor price_
	// - subject: The genre to initialize subject_
	NonFictionBook(const std::string& title, const std::string& author, double price, const std::string& subject);

	// Copy Constructor
	NonFictionBook(const NonFictionBook& book);

	// Assignment operator
	NonFictionBook& operator =(const NonFictionBook& book);

	// Destructor
	~NonFictionBook();

	// Method to display book private data members title_, author_, price_ and subject_
	// virtual function overriden from base class Book
	virtual void displayBookInfo() override;

	// Getter Function
	// Returns subject_
	std::string getSubject();

	// Setter Function
	void setSubject(std::string subject);
private:
	std::string subject_;
};