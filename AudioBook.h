#pragma once
#include "Book.h"

class AudioBook : public Book {
public:
	// Default Constructor
	AudioBook();

	// Constructor. Initializes the BookstoreManger object.
	// Params:
	// - title: The title to satisfy Book constructor title_
	// - author: The author to satisfy Book constructor author_
	// - price: The price to satisfy Book constructor price_
	// - duration: The duration to initialize duration_
	AudioBook(const std::string& title, const std::string& author, double price, int duration);

	// Copy Constructor
	AudioBook(const AudioBook& book);

	// Assignment operator
	AudioBook& operator =(const AudioBook& book);

	// Default Destructor. Performs cleanup task for the AudioBook object
	~AudioBook();

	// Method to display book private data members title_, author_, price_ and duration_
	// virtual function overriden from base class Book
	virtual void displayBookInfo() override;

	// Getter Function to return duration_
	int getDuration();

	// Setter Function set duration_ with param duration
	void setDuration(int duration);
private:
	int duration_;
};