#include <stdio.h>

enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main(void)
{
	enum months month;
	int date;
	int year;
	const char *monthName[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	puts("Enter a date in xx/xx/xxxx format:");
	scanf("%d/%d/%d", &month, &date, &year);
	puts("");
	printf("%s %d, %d\n", monthName[month], date, year);
}//end main
