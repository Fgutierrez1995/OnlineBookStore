#include "NonFictionBook.h"

// Default Constructor
NonFictionBook::NonFictionBook() : Book(" ", " ", 0.0), subject_("") {};

// Constructor
NonFictionBook::NonFictionBook(const std::string& title, const std::string& author, double price, const std::string& subject) : Book(title, author, price), subject_(subject) {}

// Copy Constructor
NonFictionBook::NonFictionBook(const NonFictionBook& book) : Book(book) {
	subject_ = book.subject_;
}

// Assignment operator
// Returns the copied NonFictionBook object
NonFictionBook& NonFictionBook::operator =(const NonFictionBook& book) {
	NonFictionBook::setTitle(book.getTitle());
	NonFictionBook::setAuthor(book.getAuthor());
	NonFictionBook::setPrice(book.getPrice());
	subject_ = book.subject_;

	return *this;
}

// Destructor
NonFictionBook::~NonFictionBook(){}

// overriden virtual function to display NonFictionBook object title_, author_, price_ and subject_
void NonFictionBook::displayBookInfo() {
	std::cout << "Title : " << NonFictionBook::getTitle() << std::endl;
	std::cout << "Author : " << NonFictionBook::getAuthor() << std::endl;
	std::cout << "Price : " << NonFictionBook::getPrice() << std::endl;
	std::cout << "Subject : " << subject_ << std::endl << std::endl;
}

// Getter function to return subject_
std::string NonFictionBook::getSubject() {
	return subject_;
}

// Setter function to set subject_ with param subject_
void NonFictionBook::setSubject(std::string subject) {
	subject_ = subject;
}