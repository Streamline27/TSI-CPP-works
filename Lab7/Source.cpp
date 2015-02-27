#include <iostream>
#include <Vector>

using namespace std;

struct Computer{
	char type[15];
	int year;
	int price;
	void burnItDown(){
		cout << "Computer is on fire! /n";
	}
};

struct ComputerList{
private:
	vector<Computer> computers;
public:
	void add(Computer computer){
		computers.push_back(computer);
	}
	void addManual(){
		Computer computer;
		cout << "Enter type: ";
		cin >> computer.type;
		cout << "Enter year: ";
		cin >> computer.year;
		cout << "Enter price: ";
		cin >> computer.price;
		computers.push_back(computer);

	}
	Computer get(int n){
		return computers.at(n);
	}
	void deleteWhereYear(int year){
		for (vector<Computer>::iterator it = computers.begin(); it != computers.end(); ++it)
		{
			if (it->year == year) computers.erase(it);
		}
	}
};



int main(){
	ComputerList computerList;
	computerList.addManual();
	computerList.addManual();
	return 0;
}