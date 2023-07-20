#include "Book.h"

// Default Constructor
Book::Book() : title_(" "), author_(" "), price_(0) {}

// Constructor
Book::Book(const std::string& title, const std::string& author, double price) : title_(title), author_(author), price_(price) {}

// Destructor
Book::~Book() {}

// Getter function to return title_
std::string Book::getTitle() const {
	return title_;
}

// Getter function to return author_
std::string Book::getAuthor() const {
	return author_;
}

// Getting function to return price_
double Book::getPrice() const {
	return price_;
}

// Setter function to set title_ with new value
void Book::setTitle(std::string title) {
	title_ = title;
}

// Setter function to set author_ with new value
void Book::setAuthor(std::string author) {
	author_ = author;
}

// Setter function to set price_ with new value
void Book::setPrice(double price) {
	price_ = price;
}

// Method to display Book data members.
void Book::displayBookInfo() {
	std::cout << "Title : " << title_ << std::endl;
	std::cout << "Author : " << author_ << std::endl;
	std::cout << "Price : " << price_ << std::endl << std::endl;
}