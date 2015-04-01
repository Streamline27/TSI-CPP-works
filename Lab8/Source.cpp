#include <iostream>

using namespace std;

void stars(int);
void square(int);

int main(){
	int n;

	cout << "Enter N:";
	cin >> n;

	square(n);
	system("PAUSE");
	return 0;
}

void stars(int n){
	for (int i = 0; i < n; i++) cout << "*";
	cout << "\n";
}

void square(int n){
	for (int i = 0; i < n; i++) stars(n);
}