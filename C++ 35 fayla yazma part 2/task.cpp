#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#pragma region Book Management System

class Book {
private:
    int id;
    string title;
    string author;
    double price;

public:
    Book() = default;

    Book(int id, string title, string author, double price) {
        SetId(id);
        SetTitle(title);
        SetAuthor(author);
        SetPrice(price);
    }
    int GetId() const { return id; }
    string GetTitle() const { return title; }
    string GetAuthor() const { return author; }
    double GetPrice() const { return price; }

    void SetId(int id) {
        if (id > 5) {
            this->id = id;
            return;
        }
        throw string("invalid Id error");
    }

    void SetTitle(string title) {
        if (!title.empty()) {
            this->title = title;
            return;
        }
        throw string("invalid Title error");
    }

    void SetAuthor(string author) {
        if (!author.empty()) {
            this->author = author;
            return;
        }
        throw string("invalid author error");
    }

    void SetPrice(double price) {
        if (price >= 0) {
            this->price = price;
            return;
        }
        throw string("invalid price error.");
    }

    void Show() const {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << " AZN" << endl;
    }
};

class Database {
private:
    vector<Book> books;

public:
    bool Exists(int id) const {
        for (const Book& book : books) {
            if (book.GetId() == id) {
                return true;
            }
        }
        return false;
    }

    void AddBook(Book book) {
        if (Exists(book.GetId())) {
            cout << "This ID already exists!" << endl;
            return;
        }
        if (book.GetPrice() < 0) {
            cout << "Price cannot be negative!" << endl;
            return;
        }
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }

    void ShowBooks() const {
        if (books.empty()) {
            cout << "No books found!" << endl;
            return;
        }
        for (const Book& book : books) {
            cout << "------------------------" << endl;
            book.Show();
        }
    }

    void SearchBook(int id) const {
        for (const Book& book : books) {
            if (book.GetId() == id) {
                book.Show();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void DeleteBook(int id) {
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].GetId() == id) {
                books.erase(books.begin() + i);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void WriteToFile(string path = "books.txt") const {
        ofstream fs(path, ios::out);
        if (fs.is_open()) {
            for (const Book& p : books) {
                fs << p.GetId() << '#' << p.GetTitle() << '#' << p.GetAuthor() << '#' << p.GetPrice() << "\n";
            }
        }
        else {
            throw string("file couldn't open...");
        }
        fs.close();
    }

    void ReadFromFile(string path = "books.txt") {
        ifstream fs(path);
        if (fs.is_open()) {
            books.clear();
            while (!fs.eof()) {
                string row;
                getline(fs, row); 

                if (row.empty()) continue;

                int counter = 0; 
                string str_id, title, author, str_price;

                for (char character : row) {
                    if (character != '#' && counter == 0) {
                        str_id += character;
                    }
                    else if (character != '#' && counter == 1) {
                        title += character;
                    }
                    else if (character != '#' && counter == 2) {
                        author += character;
                    }
                    else if (character != '#' && counter == 3) {
                        str_price += character;
                    }
                    else { 
                        counter++;
                    }
                }

                if (!str_id.empty()) {
                    int id = stoi(str_id);
                    double price = stod(str_price); 
                    books.push_back(Book(id, title, author, price)); 
                }
            }
        }
        else {
            throw string("file couldn't open...");
        }
        fs.close();
    }
};

void main() {
    Database db;
    const string filename = "books.txt";

    try {
        db.ReadFromFile(filename);
        cout << "Data successfully loaded from file!\n" << endl;
    }
    catch (string ex) {
        cout << "Note: " << ex << " (New file will be created on save)" << endl;
    }

    try {
        db.AddBook(Book(1, "C++ Programming", "Bjarne Stroustrup", 45.50));
        db.AddBook(Book(2, "Clean Code", "Robert Martin", 35.00));

        db.WriteToFile(filename);
        cout << "\nData successfully written to file!" << endl;
    }
    catch (string ex) {
        cout << "Error: " << ex << endl;
    }
}
#pragma endregion