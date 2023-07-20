#pragma once
#include <iostream>
#include <string>

class Book {
public:
	// Default Constructor. Initializes the Book object.
	Book();

	// Constructor. Initializes the BookstoreManger object.
	// Params:
	// - title: The title to initialize title_
	// - author: The author to initialize author_
	// - price: The price to initialize price_
	Book(const std::string& title, const std::string& author, double price);

	// Default Destructor. Performs cleanup task for the Book object
	~Book();

	// Getting functions
	std::string getTitle() const;
	std::string getAuthor() const;
	double getPrice() const;

	// Setter functions
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setPrice(double price);

	// Method to display book info
	// virtual function which will be used by derived classes
	virtual void displayBookInfo();

private:
	std::string title_;
	std::string author_;
	double price_;
};