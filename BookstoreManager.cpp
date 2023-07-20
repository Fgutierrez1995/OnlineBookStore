#include "BookstoreManager.h"

BookstoreManager::BookstoreManager() {};

// This method is used to create a FictionBook Object and return the value. This method is called in AddBooks()
std::unique_ptr<FictionBook> BookstoreManager::readFictionBook() {
    std::string title, author, genre;
    double price;
    
    std::cout << "Please enter the title: ";
    std::getline(std::cin, title);

    std::cout << "Please enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Please enter the price: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

    std::cout << "Please enter the genre: ";
    std::getline(std::cin, genre);

    return std::make_unique<FictionBook>(title, author, price, genre);
}

// This method is used to create a NonFictionBook Object and return the value. This method is called in AddBooks()
std::unique_ptr<NonFictionBook> BookstoreManager::readNonFictionBook() {
    std::string title, author, subject;
    double price;

    std::cout << "Please enter the title: ";
    std::getline(std::cin, title);

    std::cout << "Please enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Please enter the price: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

    std::cout << "Please enter the subject: ";
    std::getline(std::cin, subject);

    return std::make_unique<NonFictionBook>(title, author, price, subject);
}

// This method is used to create a AudioBook Object and return the value. This method is called in AddBooks()
std::unique_ptr<AudioBook> BookstoreManager::readAudioBook() {
    std::string title, author;
    double price;
    int duration;

    std::cout << "Please enter the title: ";
    std::getline(std::cin, title);

    std::cout << "Please enter the author: ";
    std::getline(std::cin, author);

    std::cout << "Please enter the price: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

    std::cout << "Please enter the duration: ";
    std::cin >> duration;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character

    return std::make_unique<AudioBook>(title, author, price, duration);
}

// Method is used to add the return values of readFictionBook, readNonFictionBook, readAudioBook to the inventory_
void BookstoreManager::addBooks() {
    int userSelection;
    std::cout << "Please specify the type of Book you're trying to add." << std::endl;
    do {
        std::cout << "1. FictionBook, 2. NonFictionBook, 3. AudioBook, 0. Quit" << std::endl;
        std::cin >> userSelection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the newline character
        switch (userSelection) {
        case 1: {
            // Creating a FictionBook object with the return value of readFictionBook()
            std::unique_ptr<FictionBook> fictionBook = readFictionBook();
            if (fictionBook != nullptr) {
                // Adding book to inventory and transfering ownership to inventory
                inventory_.push_back(std::move(fictionBook));
            }
            break;
        }
        case 2: {
            // Creating a NonFictionBook object with the return value of readNonFictionBook()
            std::unique_ptr<NonFictionBook> nonFictionBook = readNonFictionBook();
            if (nonFictionBook != nullptr) {
                // Adding book to inventory and transfering ownership to inventory
                inventory_.push_back(std::move(nonFictionBook));
            }
            break;
        }
        case 3: {
            // Creating a AudioBook object with the return value of readAudioBook()
            std::unique_ptr<AudioBook> audioBook = readAudioBook();
            if (audioBook != nullptr) {
                // Adding book to inventory and transfering ownership to inventory
                inventory_.push_back(std::move(audioBook));
            }
            break;
        }
        case 0: {
            // User selected 0. End the AddBook() method by breaking this loop
            std::cout << "Adding Books Completed" << std::endl;
            userSelection = 0;
            break;
        }
        default:
            // User selected a invalid option. Terminating AddBook() method by breaking this loop
            std::cout << "Invalid option. No book will be added." << std::endl;
            userSelection = 0;
            break;
        }
    } while (userSelection != 0);
}

// This method is used to in the sort() algorithm. This compare two book objects by author
// and sort them by alphabetical order.
bool BookstoreManager::compareBooksPtr(const std::unique_ptr<Book>& book1, const std::unique_ptr<Book>& book2) {
    return book1->getAuthor() < book2->getAuthor();
}


void BookstoreManager::displayBooks() {
    // Using sort to organize the books by Author by calling compareBooksPtr
    sort(inventory_.begin(), inventory_.end(), compareBooksPtr);

    std::cout << "Book Inventory: " << std::endl;
    // Displaying all the inventory_ book information.
	for (const auto& book : inventory_) {
        book->displayBookInfo();
	}

    std::cout << "Shopping Cart: " << std::endl;
    // Displaying all the shoppingCart_ book information
    for (const auto& book : shoppingCart_) {
        book->displayBookInfo();
    }
}

// Method searches the inventory_ for a book with the specified title
// and removes  the book. It transfers ownership to the caller.
std::unique_ptr<Book> BookstoreManager::searchAndEraseBookByTitle(const std::string& title) {
    for (auto it = inventory_.begin(); it != inventory_.end(); ++it) {
        if ((*it)->getTitle() == title) {
            // We found a book with the matching title
            // Transfer ownership of the book from the inventory to return the value
            std::unique_ptr<Book> foundBook = std::move(*it);

            // Erase the book from the inventory
            inventory_.erase(it);

            // Return the book and transfer ownership to the return value
            return std::move(foundBook);
        }
    }
    // If no book was found, return nullptr
    return nullptr;
}


void BookstoreManager::addBookToCart() {
    // Loop to add multiple books to the shoppingCart_
    while (true) {
        std::string reqBook;
        std::cout << "Please enter Title for the requested book (or 'done' to finish): " << std::endl;
        std::getline(std::cin, reqBook);
        if (reqBook == "done") {
            break; // Exit the loop if user enters done adding books
        }
        // Use searchAndEraseBookByTitle to return a unique_ptr from the inventory_
        std::unique_ptr<Book> bookPtr = searchAndEraseBookByTitle(reqBook);
        // Check and make sure bookPtr is not a nullptr
        if (bookPtr) {
            // Add to the shoppingCart_ and transfer ownership from bookPtr to the shoppingCart_
            shoppingCart_.push_back(std::move(bookPtr));
        }
        else {
            std::cout << "No book found with the title " << reqBook << std::endl;
        }
    }
}

// Method displays the total balance in the shoppingCart_
void BookstoreManager::displayRunningTotalCart() {
    double sum = 0;
    for (const auto& book : shoppingCart_) {
        sum += book->getPrice();
    }
    std::cout << "The total balance in your shopping cart is $" << sum << " dollars" << std::endl;
}

