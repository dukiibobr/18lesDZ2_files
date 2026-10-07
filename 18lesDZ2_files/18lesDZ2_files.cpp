#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
using namespace std;



//int main()
//{


	//1

	//ofstream out("text.txt");
	//if (out.is_open())
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		char info[255];
	//		cout << "enter text: " << endl;
	//		cin >> info;

	//		out << info;
	//		out << endl;
	//	}
	//	cout << "info  saved" << endl;
	//}
	//else
	//{
	//	cout << "info NOT saved" << endl;
	//}
	//

	//
	//out.close();


	//2


	//char buff[50];
	//ifstream in;
	//in.open("text.txt", ios_base::out);
	//if (in.is_open())
	//{
	//	while (!in.eof())
	//	{
	//	in.getline(buff, 50);
	//		cout << buff<<endl;
	//	}
	//}
	//else
	//{
	//	cout << "error";
	//}
	//in.close();




	//3

const char* file = "booksDataBase.txt";


struct Book {

	int id;
	char name[50];
	char author[50];
	char publisher[50];
	char genre[50];
	int creationYear;
	float price;


	void saveToFile() {
		ofstream out(file, ios_base::app);
		out << "|";
		out << name;
		out << ":";
		out << author;
		out << ":";
		out << publisher;
		out << ":";
		out << genre;
		out << ":";
		out << creationYear;
		out << ":";
		out << price;
		out << "|";
		out << endl;

		out.close();
	}

	

};

Book* addNewBook(Book* book, int& size, Book newBook) {
	Book* temp = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = book[i];
	}
	temp[size] = newBook;
	delete[]book;
	book = temp;
	(size)++;
	return book;
}

void showBook(Book& book) {
	cout << "id:" << book.id << endl;
	cout << "name:" << book.name << endl;
	cout << "author:" << book.author << endl;
	cout << "publisher:" << book.publisher << endl;
	cout << "genre:" << book.genre << endl;
	cout << "creationYear:" << book.creationYear << endl;
	cout << "price:" << book.price << endl;
}

void searchByName(char name[], Book* books, int size) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].name, name) == 0)
		{
			showBook(books[i]);
		}
	}
}

void searchByAuthor(char name[], Book* books, int size) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].author, name) == 0)
		{
			showBook(books[i]);
		}
	}
}

void searchByPublisher(char name[], Book* books, int size) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].publisher, name) == 0)
		{
			showBook(books[i]);
		}
	}
}

void searchByGenre(char name[], Book* books, int size) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].genre, name) == 0)
		{
			showBook(books[i]);
		}
	}
}

void changeBook(Book* arr, int size, int id) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i].id == id)
		{
			showBook(arr[i]);
			cout << "enter new price:" << endl;
			cin >> arr[i].price;
		}
	}
}

void showFromFile() {
	char buff[999999];
	ifstream in;
	in.open("booksDataBase.txt", ios_base::out);
	if (in.is_open())
	{
		while (!in.eof())
		{
			in.getline(buff, 999999);
			cout << buff << endl;
		}
	}
	else
	{
		cout << "error";
	}
	in.close();
}

void main() {
	int choice;
	char name[50];

	int size = 10;
	Book* arr = new Book[10]{
		{0, "The Hobbit", "J", "H", "Fantasy", 1937, 102.99},
		{1, "1984", "George Orwell", "Secker & Warburg", "Dystopian", 1949, 250.0},
		{2, "The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Classic", 1925, 200.0},
		{3, "Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy", 1997, 300.0},
		{4, "The Da Vinci Code", "Dan Brown", "Doubleday", "Thriller", 2003, 180.0},
		{5, "The Alchemist", "Paulo Coelho", "HarperOne", "Adventure", 1988, 220.0},
		{6, "Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance", 1813, 150.0},
		{7, "The Lord of the Rings", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy", 1954, 350.0},
		{8, "To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott", "Drama", 1960, 190.0},
		{9, "The Catcher in the Rye", "J.D. Salinger", "Little, Brown", "Classic", 1951, 170.0}
	};
	do
	{
		system("cls");
		cout << "======================Menu======================" << endl;
		cout << "show all books				     [1]" << endl;
		cout << "search by name				     [2]" << endl;
		cout << "search by author			     [3]" << endl;
		cout << "search by publisher			     [4]" << endl;
		cout << "search by genre				     [5]" << endl;
		cout << "change price 				     [6]" << endl;
		cout << "add new book 				     [7]" << endl;
		cout << "save to file 				     [8]" << endl;
		cout << "show from file 				     [9]" << endl;
		cout << "exit					     [0]" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 0:
			cout << "end of program" << endl;
			break;
		case 1:
			for (int i = 0; i < size; i++)
			{
				showBook(arr[i]);
			}
			break;
		case 2:
			cout << "enter name of the book: " << endl;
			cin.getline(name, 50);
			searchByName(name, arr, size);
			break;
		case 3:
			cout << "enter name of the author: " << endl;
			cin.getline(name, 50);
			searchByAuthor(name, arr, size);
			break;
		case 4:
			cout << "enter name of the publisher: " << endl;
			cin.getline(name, 50);
			searchByPublisher(name, arr, size);
			break;
		case 5:
			cout << "enter name of the genre: " << endl;
			cin.getline(name, 50);
			searchByGenre(name, arr, size);
			break;
		case 6:
			int id;
			cout << "enter id: " << endl;
			cin >> id;
			changeBook(arr, size, id);
			break;
		case 7:
			cout << "enter name of the genre: " << endl;
			arr = addNewBook(arr, size, { 99,"w","e","r","e",999,999 });

			break;
		case 8:
			for (int i = 0; i < size; i++)
			{
			arr[i].saveToFile();
			}
			cout << "books are saved" << endl;
			break;
		case 9:
			showFromFile();
			
			break;

		default:
			cout << "wrong choice" << endl;
			break;
		}

		if (choice != 0) {
			cout << "Press any key to continue...";
			_getch();
		}

	} while (choice != 0);

}









//}