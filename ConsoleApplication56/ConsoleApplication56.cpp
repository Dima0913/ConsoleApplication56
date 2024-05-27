#include <iostream>
#include <string>

using namespace std;

class Book {
    string name;
    string author;
    int year;
    string genre;
    string publhouse;

public:
    Book() : name("No name"), author("No author"), year(0), genre("No genre"), publhouse("No publhouse") {}
    Book(string n, string a, int y, string g, string p) : name(n), author(a), year(y), genre(g), publhouse(p) {}

    void Show() const {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Genre: " << genre << endl;
        cout << "Publishing House: " << publhouse << endl;
    }

    void Input() {
        cout << "Enter name of book: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter author of book: ";
        getline(cin, author);
        cout << "Enter year of book: ";
        cin >> year;
        cin.ignore();
        cout << "Enter genre of book: ";
        getline(cin, genre);
        cout << "Enter publishing house of book: ";
        getline(cin, publhouse);
    }

    string GetName() const { return name; }
    string GetAuthor() const { return author; }
    string GetPublHouse() const { return publhouse; }

    void Edit() {
        Input();
    }
};

void PrintAllBooks(Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        books[i].Show();
        cout << endl;
    }
}

void SearchByAuthor(Book books[], int size, string author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].GetAuthor() == author) {
            books[i].Show();
            cout << endl;
        }
    }
}

void SearchByName(Book books[], int size, string name) {
    for (int i = 0; i < size; ++i) {
        if (books[i].GetName() == name) {
            books[i].Show();
            cout << endl;
        }
    }
}

void SortByName(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (books[i].GetName() > books[j].GetName()) {
                swap(books[i], books[j]);
            }
        }
    }
}

void SortByAuthor(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (books[i].GetAuthor() > books[j].GetAuthor()) {
                swap(books[i], books[j]);
            }
        }
    }
}

void SortByPublHouse(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (books[i].GetPublHouse() > books[j].GetPublHouse()) {
                swap(books[i], books[j]);
            }
        }
    }
}

int main() {
    const int size = 10;
    Book library[size];

    for (int i = 0; i < size; ++i) {
        cout << "Enter details for book " << i + 1 << ":" << endl;
        library[i].Input();
        cout << endl;
    }

    cout << "All books:" << endl;
    PrintAllBooks(library, size);

    string searchAuthor;
    cout << "Enter author to search: ";
    getline(cin, searchAuthor);
    SearchByAuthor(library, size, searchAuthor);

    string searchName;
    cout << "Enter name to search: ";
    getline(cin, searchName);
    SearchByName(library, size, searchName);

    cout << "Books sorted by name:" << endl;
    SortByName(library, size);
    PrintAllBooks(library, size);

    cout << "Books sorted by author:" << endl;
    SortByAuthor(library, size);
    PrintAllBooks(library, size);

    cout << "Books sorted by publishing house:" << endl;
    SortByPublHouse(library, size);
    PrintAllBooks(library, size);

}