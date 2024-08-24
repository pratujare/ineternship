#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full!" << endl;
        return;
    }

    cout << "Enter title: ";
    getline(cin, books[bookCount].title);
    cout << "Enter author: ";
    getline(cin, books[bookCount].author);
    cout << "Enter ISBN: ";
    getline(cin, books[bookCount].isbn);
    books[bookCount].isAvailable = true;
    bookCount++;
    cout << "Book added successfully." << endl;
}

void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    getline(cin, query);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == query || books[i].author == query || books[i].isbn == query) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", ISBN: " << books[i].isbn << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No book found." << endl;
    }
}

void checkoutBook() {
    string isbn;
    cout << "Enter ISBN to checkout: ";
    getline(cin, isbn);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn && books[i].isAvailable) {
            books[i].isAvailable = false;
            cout << "Book checked out successfully." << endl;
            return;
        }
    }
    cout << "Book not available for checkout." << endl;
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN to return: ";
    getline(cin, isbn);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].isbn == isbn) {
            if (!books[i].isAvailable) {
                books[i].isAvailable = true;
                cout << "Book returned successfully." << endl;
            } else {
                cout << "Book was not checked out." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", ISBN: " << books[i].isbn << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                displayBooks();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
