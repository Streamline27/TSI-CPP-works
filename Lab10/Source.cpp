#include<iostream>
#include<vector>
#include<random>
#include<time.h>

using namespace std;


void showDefault(vector<int>&);
void showUpgraded(vector<int>&);
void insertTwenty(vector<int>&);
void deleteNegatives(vector<int>&);
void swapMiddle(vector<int>&);
void demoFunctions(vector<int>&);

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
	cout << endl;

	cout << "Show vector by iterator method: " << endl;
	showUpgraded(testedVec);
	cout << endl;

	cout << "Vector after insertion" << endl;
	insertTwenty(testedVec);
	showUpgraded(testedVec);
	cout << endl;

	cout << "Vector after deletion" << endl;
	deleteNegatives(testedVec);
	showUpgraded(testedVec);
	cout << endl;

	cout << "Vector after swapping middle elements" << endl;
	swapMiddle(testedVec);
	showUpgraded(testedVec);
	cout << endl;

	demoFunctions(testedVec);

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
		if ((*ptrCurrent != -20)&&(*ptrCurrent<0)) ptrCurrent = testedVector.erase(ptrCurrent);
		else ptrCurrent++;
	}
}

void swapMiddle(vector<int>& testedVector){
	vector<int>::iterator ptrFirst = testedVector.begin() + 2;
	vector<int>::iterator ptrLast = testedVector.end() - 3;

	reverse(ptrFirst, ptrLast);
}

void demoFunctions(vector<int>& testedVector){
	// Demo pushback
	cout << "Adding 5 numbers 100 and removing 4 of them" << endl;
	for (int i = 0; i < 5; i++) testedVector.push_back(100);
	for (int i = 0; i < 4; i++) testedVector.pop_back();
	showUpgraded(testedVector);
	cout << endl;

	// Demo front/back
	cout << "Last element of vector is: " << testedVector.back() << endl;
	cout << "First element of vector is: " << testedVector.front() << endl;
	cout << endl;

	// Demo assign
	auto ptrFirst = testedVector.begin()+1;
	auto ptrLast = testedVector.end()-1;
	vector<int> second;
	second.assign(ptrFirst, ptrLast);

	cout << "New vector contains all the elements except last" << endl;
	showUpgraded(second);
	cout << endl;

	// Demo swap
	cout << "Swapping tested and second vector content" << endl;
	swap(testedVector, second);
	showUpgraded(second);
}