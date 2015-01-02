#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int n; //Size of array

//===================================
//========== Helper functions =======
void readInt(char* message, int &n){
	printf(message);
	scanf_s("%d", &n);
}

void printArray(double* a){
	for (int i = 0; i < n; i++) printf("%f |", a[i]);
	printf("\n");
}


double* initManual(int n){
	double* a = new double[n];
    double k;
	for (int i = 0; i < n; i++){
		scanf_s("%lf", &k);
		a[i] = k;
	}
	return a;
}

double* initAuto(int n,int threshold){
	double* a = new double[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) a[i] = (rand() % threshold)-threshold/2;
	return a;
}

//==============================
//==== Task functions ==========

// Task 3. (Zero sorting array)
void swap(double* a, double* b){
	double tmp = *a;
	*a = *b;
	*b = tmp;
}
void zeroSort(double* a){
	double* lo = a;
	for (double* hi = a; hi < a+n; hi++) if (*hi == 0) swap(hi, lo++);
}
// Task 1. (Finding minimum)
double min(double* a){
	double min = a[0];
	for (int i = 1; i < n; i++) if (a[i] < min) min = a[i];
	return min;
}

// Task 2. (Sum between two negatives)
double findSum(double* a){
	//Finding first occurrence of negative number
	int first;
	for (first = 0; (first < n) && (a[first] >= 0); first++);
	if (first == n){
		printf("First negative is undetected...\n");
		return 0;
	}
	//Finding last occurrence of negative number
	int last;
	for (last = n - 1; (last >= 0) && (a[last] >= 0); last--);
	if (last == first){
		printf("Last negative is undetected...\n");
		return 0;
	}
	//Finding sum
	double sum = 0;
	cout << first << endl;
	cout << last << endl;
	for (int i = first+1; i < last; i++) sum += a[i];

	return sum;
}

int main(){
	readInt("Enter N: ", n);
	//double* a = initAuto(n, 2);
	double* a = initManual(n);
	printArray(a);
	printf("\n1)Minimum in array: %f \n\n", min(a));
	printf("2)Sum between two negative occurencies: %f \n\n", findSum(a));
	zeroSort(a);
	printf("3)Array after negative sort: \n");
	printArray(a);
	main();
	return 0;
}