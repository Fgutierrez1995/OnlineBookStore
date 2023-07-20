#include "FictionBook.h"
// Default Constructor
FictionBook::FictionBook() : Book(" ", " ", 0), genre_(" ") {}

// Constructor
FictionBook::FictionBook(const std::string& title, const std::string& author, double price, const std::string& genre) : Book(title, author, price), genre_(genre) {}

// Destructor
FictionBook::~FictionBook() {}

// Copy Constructor
FictionBook::FictionBook(const FictionBook& book) : Book::Book(book) {
	std::cout << "Copy constructor called " << std::endl;
	genre_ = book.genre_;
}

// Assignment operator
// Returns the copied FictionBook object
FictionBook& FictionBook::operator =(const FictionBook& book) {
	std::cout << "Assignment operator called " << std::endl;
	FictionBook::setTitle(book.getTitle());
	FictionBook::setAuthor(book.getAuthor());
	FictionBook::setPrice(book.getPrice());
	genre_ = book.genre_;

	return *this;
}

// Getter function to return genre_
std::string FictionBook::getGenre() const {
	return genre_;
}

// Setter function to set genre_ with param genre
void FictionBook::setGenre(std::string genre) {
	genre_ = genre;
}

// overloaded virtual function to display FictionBook object title_, author_, price_ and genre_
void FictionBook::displayBookInfo() {
	std::cout << "Title : " << Book::getTitle() << std::endl;
	std::cout << "Author : " << Book::getAuthor() << std::endl;
	std::cout << "Price : " << Book::getPrice() << std::endl;
	std::cout << "Genre : " << genre_ << std::endl << std::endl;
}

