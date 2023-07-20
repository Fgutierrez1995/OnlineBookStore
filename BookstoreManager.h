#pragma once
#include "FictionBook.h"
#include "NonFictionBook.h"
#include "AudioBook.h"
#include "Book.h"
#include <vector>
#include <algorithm>

class BookstoreManager {
public:
	// Default Constructor. Initializes the BookstoreManger object.
	BookstoreManager();
	// Default Destructor. Performs cleanup task for the BookstoreManager object
	~BookstoreManager() = default;

	// Used to read user input to create a FictionBook object.
	// Returns: A unique_ptr to the created FictionBook.
	std::unique_ptr<FictionBook> readFictionBook();

	// Used to read user input to create a NonFictionBook object.
	// Returns: A unique_ptr to create a NonFictionBook
	std::unique_ptr<NonFictionBook> readNonFictionBook();

	// Used to read user input to create a AudioBook object.
	// Returns: A unique_ptr to create a AudioBook.
	std::unique_ptr<AudioBook> readAudioBook();

	// Used to add the return values of readFictionBook, readNonFictionBook, readAudioBook to the inventory_
	void addBooks();

	// Method to display all books in inventory_ and in the shoppingCart_
	void displayBooks();

	// Method searches the inventory_ for a book with the specified title
	// and removes  the book. It transfers ownership to the caller.
	// Params:
	// - title: The title of the book to search for in the inventory.
	// Returns: a unique_ptr to the Book matching the title, or nullptr if not found.
	std::unique_ptr<Book> searchAndEraseBookByTitle(const std::string& title);

	// Method calls searchAndEraseByTitle to add the book to the shoppingCart_
	void addBookToCart();

	// Method displays the total balance in the shoppingCart_
	void displayRunningTotalCart();
	

private:
	// Data member to hold books in the shoppingCart_;
	std::vector<std::unique_ptr<Book>> shoppingCart_;
	// Data member to hold books in the inventory_;
	std::vector<std::unique_ptr<Book>> inventory_;
	// Comparator function used to sort books in the inventory_ based on book titles.
	static bool compareBooksPtr(const std::unique_ptr<Book>& book1, const std::unique_ptr<Book>& book2);
};

