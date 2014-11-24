#include <iostream>
#include <stdio.h>

using namespace std;

void readInt(char* message, int &n){
	printf(message);
	scanf_s("%d", &n);
}

bool isLeapYear(const int &year){
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0) return true;
			else return false;
		}
		else return true;
	}
	else return false;
}

void initDaysOfWeek(char** daysOfWeek){
	daysOfWeek[0] = "Monday";
	daysOfWeek[1] = "Tuesday";
	daysOfWeek[2] = "Wednesday";
	daysOfWeek[3] = "Thursday";
	daysOfWeek[4] = "Friday";
	daysOfWeek[5] = "Satruday";
	daysOfWeek[6] = "Sunday";
}

int main(){
	//Input year
	int year;
	readInt("Enter year: ", year);
	//Init days of week array;
	char *daysOfWeek[7];
	initDaysOfWeek(daysOfWeek);

	/* Main loop */
	int day = 0, currentYear = 1900;
	while (currentYear < year)
	{
		if (isLeapYear(currentYear)) day = day + 2;
		else day++;
		day = day % 7;
		currentYear++;

	}

	printf("First day of the year is: %s \n", daysOfWeek[day]);

	system("PAUSE;");
	return 0;
}