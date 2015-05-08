#include<iostream>
#include<string>
#include<fstream>

using namespace std;
/************************************************************/

enum Action{
	VIEW_DATA=1, ADD_DATA, DELETE_DATA, EXIT
};

struct Computer{
	char type[35];
	int year;
	double price;
};

/************************************************************/

void parseAction();
Computer readComputer();
void showComputer(Computer&);
void deleteByYear(Computer*, int&, int);

void showMainMenu();
void dataAdd();
void dataDelete();
void dataView();

char* fileName = "data.d";

int main(){
	while (true){
		showMainMenu();
		parseAction();
	}
	system("PAUSE");
	return 0;
}

void showMainMenu(){
	cout << "======  Main menu  ======" << endl;
	cout << "        1) View data." << endl;
	cout << "        2) Add data." << endl;
	cout << "        3) Delete." << endl;
	cout << "        4) Exit." << endl;
	cout << "Enter number of menu>";
}


void dataAdd(){
	cout << "======  Add record:"<< endl;
	ofstream f;
	f.open(fileName, ios::binary|ios::app);

	Computer& c = readComputer();

	f.write((char*)&c, sizeof(Computer));
	f.close();
	system("CLS");
	cout << "Writting done succesfully..." << endl << endl;
}

void dataView(){
	system("CLS");
	cout << "======  Records in file:" << endl;

	// Opening file
	ifstream f(fileName, ios::binary);
	if (!f.is_open()){
		cout << "File is empty." << endl;
		cout << "Try to insert some data first." << endl << endl;
		return;
	}


	// Getting size of file;
	f.seekg(0, ios::end);
	int fileSize = f.tellg();
	f.seekg(0, ios::beg);

	// Allocating array of records
	int numComputers = fileSize / sizeof(Computer);
	Computer* computers = new Computer[numComputers];

	// Reading all data;
	f.read((char*)computers, fileSize);

	cout << endl <<"  Total number of records: " << numComputers << endl << endl;

	// Showing data
	for (int i = 0; i < numComputers; i++)
	{
		cout << endl;
		showComputer(computers[i]);
		cout << endl;
	}

	f.close();
}

void dataDelete(){
	cout << "======  Deleting from file by year:" << endl;

	// Opening file
	fstream f(fileName, ios::in | ios::binary);
	if (!f.is_open()){
		cout << "File is empty." << endl;
		cout << "Try to insert some data first." << endl << endl;
		return;
	}

	// Getting size of file;
	f.seekg(0, ios::end);
	int fileSize = f.tellg();
	f.seekg(0, ios::beg);

	// Allocating array of records
	int numComputers = fileSize / sizeof(Computer);
	Computer* computers = new Computer[numComputers];

	// Reading all data;
	f.read((char*)computers, fileSize);

	// Deleting computers with supplied year from array
	cout << endl << "  Enter year: ";
	int year;
	cin >> year;

	int oldNum = numComputers;
	deleteByYear(computers, numComputers, year);

	f.close();

	// Writting new data to file
	f.open(fileName, ios::binary | ios::trunc | ios::out);
	for (int i = 0; i < numComputers; i++)
	{
		f.write((char*)(computers+i), sizeof(Computer));
	}

	system("CLS");
	cout << endl <<"  Deleted " << oldNum - numComputers << " records in total." << endl << endl;
	
	f.close();
}

/************************************************************
****************    Backend functions     *******************
************************************************************/

void parseAction(){
	// Reading user choice of action
	int action;
	cin >> action;
	cin.ignore();
	// Chosing what action to perform
	switch (action)
	{
	case VIEW_DATA:
		dataView();
		break;
	case ADD_DATA:
		dataAdd();
		break;
	case DELETE_DATA:
		dataDelete();
		break;
	case EXIT:
		exit(0);
	default:
		cout << "Illegal action...";
		break;
	}
}

Computer readComputer(){
	Computer c;
	cout << "Enter type: ";

	cin.getline(c.type, sizeof(c.type));
	cout << "Enter year: ";
	cin >> c.year;
	cout << "Enter price: ";
	cin >> c.price;
	return c;
}

void showComputer(Computer& c){
	cout << "  type: " << c.type << endl;
	cout << "  year: " << c.year << endl;
	cout << "  price: " << c.price << endl;
}

void deleteByYear(Computer* computers, int& size, int year){
	/* Both computers and size will be modified */
	Computer* lo = computers;
	Computer* hi = computers + size - 1;

	while (lo<=hi)
	{
		if (lo->year == year){
			*lo = *hi;
			hi--;
			size--;
		}
		else lo++;
	}
}

