#include<iostream>
#include<vector>
#include<random>
#include<time.h>

using namespace std;

void showDefault(vector<int>&);
void showUpgraded(vector<int>&);
void insertTwenty(vector<int>&);
void deleteNegatives(vector<int>&);

const int NUM_ELEMENTS = 10;

int main(){
	// Creating empty integer vector
	vector<int> testedVec;

	// Adding random numbers
	srand(time(NULL));
	for (int i = 0; i < NUM_ELEMENTS; i++) testedVec.push_back(rand() % 31 - 15);

	// Showing vector
	//showDefault(testedVec);

	cout << "Show vector by default method: " << endl;
	showDefault(testedVec);

	cout << "Show vector by iterator method: " << endl;
	showUpgraded(testedVec);

	cout << "Vector after insertion" << endl;
	insertTwenty(testedVec);
	showUpgraded(testedVec);

	cout << "Vector after deletion" << endl;
	deleteNegatives(testedVec);
	showUpgraded(testedVec);


	system("PAUSE");
	return 1;
}

//   =========== Task 1 ===================
void showDefault(vector<int>& testedVector){
	for (int i = 0; i < testedVector.size(); i++) cout << testedVector.at(i) << " ";
	cout << endl;
}

void showUpgraded(vector<int>& testedVector){
	for (vector<int>::iterator ptr = testedVector.begin(); ptr != testedVector.end(); ptr++){
		cout << *ptr << " ";
	}
	cout << endl;
}

//   =========== Task 2 ===================
void insertTwenty(vector<int>& testedVector){
	vector<int>::iterator ptrCurrent = testedVector.begin();

	while (ptrCurrent != testedVector.end()){
		if (*ptrCurrent < 0)
		{
			ptrCurrent = testedVector.insert(++ptrCurrent, -20);
		}
		ptrCurrent++;
	}
}

void deleteNegatives(vector<int>& testedVector){
	vector<int>::iterator ptrCurrent = testedVector.begin();

	while (ptrCurrent!=testedVector.end())
	{
		if (*ptrCurrent != -20) ptrCurrent = testedVector.erase(ptrCurrent);
		else ptrCurrent++;
	}
}