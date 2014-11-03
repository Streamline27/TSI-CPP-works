#include <stdio.h>
#include <list>

using namespace std;

void readInt(char* message, int& n){
	printf(message);
	scanf_s("%d", n);
}

// This is function returns N'h prime number
list<int> primeCreator(int n) {
	list<int> l = { 2 };
	bool check = true;
	for (int i = 2; i <= n; i++){
		for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
			check = check && !(i % *it);
		}
		if (check) l.push_back(i);
	}
	return l;
}

int factorial(int a){
	return a > 1 ? a*factorial(a - 1) : 1;
}