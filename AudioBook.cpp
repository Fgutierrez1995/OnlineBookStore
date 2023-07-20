#include "AudioBook.h"
// Default Constructor
AudioBook::AudioBook() : Book(" ", " ", 0.00), duration_(0) {}

// Constructor
AudioBook::AudioBook(const std::string& title, const std::string& author, double price, int duration) : Book(title, author, price), duration_(duration) {}

// Copy Constructor
AudioBook::AudioBook(const AudioBook& book) : Book(book) {
	duration_ = book.duration_;
}

// Assignment operator
// Returns the copied AudioBook object
AudioBook& AudioBook::operator=(const AudioBook& book) {
	AudioBook::setTitle(book.getTitle());
	AudioBook::setAuthor(book.getAuthor());
	AudioBook::setPrice(book.getPrice());
	duration_ = book.duration_;

	return *this;
}

// Destructor
AudioBook::~AudioBook(){}

// overriden virtual function to display AudioBook object title_, author_, price_ and duration_
void AudioBook::displayBookInfo() {
	std::cout << "Title : " << AudioBook::getTitle() << std::endl;
	std::cout << "Author : " << AudioBook::getAuthor() << std::endl;
	std::cout << "Price : " << AudioBook::getPrice() << std::endl;
	std::cout << "Duration : " << duration_ << " minutes " << std::endl << std::endl;
}

// Setter Function set duration_ with param duration
void AudioBook::setDuration(int duration) {
	duration_ = duration;
}

// Getter Function to return duration_
int AudioBook::getDuration() {
	return duration_;
}