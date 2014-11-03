#include <iostream>
#include <stdio.h>
#include "taskf.h"

using namespace std;

//ME
//  GA
//    CHA
//       GE
//         S!!!!!!!!!!!!!!!!
//
//
//
//
//
//
//
int main(){
	task1();
	list<int> l = primeCreator(7);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << ' ' << *it;
	return 0;
}