#include "BookstoreManager.h"
#include <iostream>

int main() {
	BookstoreManager manager;
	
	// Adding books to the BookstoreManager::inventory_
	manager.addBooks();
	// Displaying the inventory_ and shoppingCart_ books
	manager.displayBooks();
	// Add books to the shoppingCart
	manager.addBookToCart();
	// Displaying the inventory_ and shoppingCart_ books
	manager.displayBooks();
	// Displaying the total balance in the shoppingCart_ books
	manager.displayRunningTotalCart();

	return 0;
}