Project Idea: Online Bookstore

Description:
Create an online bookstore application that allows users to browse, search, and purchase books. The application should have a hierarchical structure of classes using inheritance, which models different types of books and their relationships.

Classes:

Book (Base Class):

Properties: title, author, price
Methods: getters and setters for the properties, displayBookInfo() to display book details
FictionBook (Derived Class):

Inherits from the Book class
Additional Property: genre
Additional Method: displayBookInfo() to override the base class method and include genre information
NonFictionBook (Derived Class):

Inherits from the Book class
Additional Property: subject
Additional Method: displayBookInfo() to override the base class method and include subject information
AudioBook (Derived Class):

Inherits from the Book class
Additional Property: duration
Additional Method: displayBookInfo() to override the base class method and include duration information
Features:

The application should allow users to add new books, either fiction or non-fiction, to the bookstore inventory.
Users should be able to search for books by title, author, genre, or subject.
The application should provide an option to display all the books available in the inventory, including their specific details.
Users should be able to purchase books, and the application should update the inventory accordingly.
Additional Enhancements:

Implement a shopping cart feature that allows users to add books before making a purchase.
Add error handling for invalid input, such as searching for a book that doesn't exist.
Implement file handling to store book information persistently.