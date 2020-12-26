//Christopher Ray
//C Programming
//A menu system using an array of function pointers

#include <stdio.h>
#include <stdlib.h>

void minimum(int x[3][4]);
void maximum(int x[3][4]);
void printArray(int x[3][4]);
void average(int x[3][4]);


int main(void)
{
	int choice = 0;
	void (*processGrades[5])(int[3][4]) = { printArray, minimum, maximum, average};
	
	int studentGrades[3][4] = 
	{
	{ 77, 68, 86, 73 },
	{ 96, 87, 89, 78 },
	{ 70, 90, 86, 81 }
	};		
	

	do
	{
	puts("Enter a choice:");
	puts("  0  Print the array of grades");
	puts("  1  Find the minimum grade");
	puts("  2  Find the maximum grade");
	puts("  3  Print the average on all tests for each student");
	puts("  4  End program");

	scanf("%d", &choice);

	if( choice == 4 )
		exit( 0 );
		
	(*processGrades[choice])(studentGrades);

	}
	while(choice >= 0 && choice <5);
	



	return 0;
}//end main function

void printArray(int x[3][4])
{
	int i = 0; //counter
    int j = 0;	//counter		
	
	
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
			printf( "%d ", x[i][j]);
		
		puts("");//newline
	}//end for
	
}//end function printArray

void minimum(int x[3][4])
{
	
	int i = 0;
	int j = 0;
	int lowGrade = 100;
	
	for(i = 0; i < 3; i++)
	{
		for( j= 0; j < 4; j++)
		{
			if( x[i][j] < lowGrade)
			{
				lowGrade = x[i][j];
			}//end if
		}//end for
	}//end for
	
	printf( "The lowest grade was %d.\n", lowGrade);
	
}//end function minimum

void maximum(int x[3][4])
{
	
	int i = 0;
	int j = 0;
	int highGrade = 0;
	
	for(i = 0; i < 3; i++)
	{
		for( j= 0; j < 4; j++)
		{
			if( x[i][j] > highGrade)
			{
				highGrade = x[i][j];
			}//end if
		}//end for
	}//end for
	
	printf( "The highest grade was %d.\n", highGrade);
}//end function maximum

void average(int x[3][4])
{
	int i = 0; //counter
	int j = 0; //counter
	int total = 0;
	
	puts("Averages are:");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 4; j++)
		{
			total += x[i][j];
		}
		
		total = total / 4;
		printf("%d\n", total);
		total = 0;
	}
}//end function average


