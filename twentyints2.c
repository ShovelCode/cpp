#include <stdio.h>
#include <stddef.h>
#define SIZE 20

int main(void){

	unsigned int i = 0;  //loop control
	unsigned int j = 0;  //loop control
	//int duplicate = 0; //acts as a boolean value
	int nums[SIZE] = {0}; //20 integers initialized to 0
	int nums2[SIZE] = {0}; //20 integers initialized to 0;

	puts("Enter 20 integers between 10 and 100");

	for(i = 0; i < SIZE; i++)
	    scanf("%d", &nums[i]);
	
	for(i = 0; i < SIZE; i++) {
		
		for( j = 0; j < SIZE; j++){
			if (nums[i] == nums2[j] && i != j)
	
	}//end for loop of i


	puts("");//a new line

	puts("The nonduplicate values are");
	for(i = 0; i < SIZE; i++){
		//add check for 0
		printf("%d "nums2[i]);
	}//end for loop
	return 0; //old compilers
}//end function main

	//add one function that sorts the arrays from smallest to largest, display that
