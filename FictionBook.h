#pragma once
#include "Book.h"

class FictionBook : public Book {
public:
	// Default Constructor
	FictionBook();

	// Constructor. Initializes the BookstoreManger object.
	// Params:
	// - title: The title to satisfy Book constructor title_
	// - author: The author to satisfy Book constructor author_
	// - price: The price to satisfy Book constructor price_
	// - genre: The genre to initialize genre_
	FictionBook(const std::string& title, const std::string& author, double price, const std::string& genre);

	// Copy Constructor
	FictionBook(const FictionBook& book);

	// Assignment operator
	FictionBook& operator =(const FictionBook& book);

	// Default Destructor. Performs cleanup task for the FictionBook object
	~FictionBook();
	
	// Getter methods
	std::string getGenre() const;

	// Setter methods
	void setGenre(std::string genre);

	// Method to display book private data members title_, author_, price_ and genre_
	// virtual function overriden from base class Book
	virtual void displayBookInfo() override;

private:
	std::string genre_;
};