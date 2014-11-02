#include <stdio.h>

using namespace std;

void readInt(char* message, int& n){
	printf(message);
	scanf_s("%d", n);
}