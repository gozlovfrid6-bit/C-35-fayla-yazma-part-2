//#include<iostream>
//#include<sstream>
//#include<vector>
//#include<fstream>
//using namespace std;
//#pragma region tekrar parcalamaq sstreami
////void main() {
////	stringstream ss;
////	ss << "Mahmud 45 Leyla 33";
////	string name1,name2;
////	int age1,age2;
////
////	ss >> name1;
////	ss >> age1;
////	ss >> name2;
////	ss >> age2;
////
////	cout << "name: " << name1 << endl;
////	cout << "age: " << age1 << endl;
////	cout << "name: " << name2 << endl;
////	cout << "age: " << age2 << endl;
////}
//#pragma endregion
//
//
//#pragma region file with object
//
//class Person {
//public:
//	string name;
//	int age;
//	Person() = default;
//	Person(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//	void Show() const {
//		cout << "Name: " << name << endl;
//		cout << "age: " << age << endl;
//	}
//};
//
//class Database {
//public:
//	vector<Person>people;
//	void AddPerson(Person person) {
//		people.push_back(person);
//	}
//	void ShowPeople() {
//		for (Person p : people) // hazir iterasiya personlarin uzerinde gezir
//		{
//			p.Show();
//			cout << "___________" << endl;
//		}
//	}
//	void DeleteLastPerson() {
//		people.pop_back();
//	}
//};
//
//void WriteToFile(const vector<Person>& people, string path = "people.txt") {
//	ofstream fs(path, ios::out);
//	if (fs.is_open()) {
//		for (Person p : people) // (int i,i<people.size();i++) ,sistem vectorunda hazir iterasiya var personlarda gezecek siraynan
//		{
//			// ox fayla dogru gedir yazir ona + # ile ayirirq
//			fs << p.name << '#' << p.age << "\n";
//		}
//	}
//	else {
//		throw string("file coulmdn't open...");
//	}fs.close();
//}
//
//void ReadFromFile(vector<Person>& people, string path = "people.txt") {
//	ifstream fs(path);
//	if (fs.is_open()) {
//		while (!fs.eof()) {//faylin sonunu bildirir
//			string row;
//			getline(fs, row);// 1 setri gotururuk
//			int counter = 0;// # lerin sayi(fieldleri ayirmaq ucun)
//			Person p;
//			string str_age;
//
//			// goturduyt setrdeki her bir simvolun uzerinde gezecek
//			for (char character : row)
//			{
//				if (character != '#' && counter == 0) {
//					p.name += character;
//				}
//				else if (character != '#' && counter == 1) {
//					str_age += character;
//				}
//				else { //character=='#' olsa
//					counter++;
//				}
//			}
//			if (str_age.size() != 0) {
//				p.age = stoi(str_age);// string to int ucundur. p ya gedir
//				people.push_back(p);//elave eledik person vectoruna
//			}
//		}
//	}
//	else {
//		throw string("file coulmdn't open...");
//	}
//	fs.close();
//}
//
//void main() {
//	Database db;
//	try
//	{
//
//		ReadFromFile(db.people);
//	}
//	catch (string ex)
//	{
//		cout << ex << endl;
//		WriteToFile(db.people); // ilk defe acanda fayli yaratsinda deye
//	}
//	int choice;
//	do
//	{
//		cout << "1.Show people \n2.Add person\n3.Delete last person\n0.Exit\nChoose: ";
//		cin >> choice;
//		system("cls");
//		if (choice == 1) {
//			db.ShowPeople();
//		}
//		else if (choice == 2) {
//			Person newPerson;
//			cin.ignore();
//			cout << "Name: ";
//			getline(cin, newPerson.name);
//			cout << "Age: ";
//			cin >> newPerson.age;
//			db.AddPerson(newPerson);
//			WriteToFile(db.people);
//		}
//		else if (choice == 3) {
//			db.DeleteLastPerson();
//			WriteToFile(db.people);
//		}
//		else {
//			if (choice == 0) {
//				cout << "good bye..." << endl;
//			}
//			else {
//				cout << "wrong input" << endl;
//			}
//		}
//	} while (choice != 0);
//}
//
//#pragma endregion
