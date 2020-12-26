/*
 * twentyints.c
 *
 *  Created on: Mar 26, 2015
 *      Author: chris
 */

#include <stdio.h>
#include <stddef.h>
#define SIZE 20

void bSort(int a[], int size);

int main(){

	unsigned int i  = 0;    //loop control
	unsigned int j  = 0;    //loop control
	int duplicate   = 0;    //acts as a boolean value
	int nums[SIZE]  = {0};  //20 integers initialized to 0
	int nums2[SIZE] = {0};  //20 integers initialized to 0;

	puts("Enter 20 integers between 10 and 100");

	for(i = 0; i < SIZE; i++)
	    scanf("%d", &nums[i]);

	for(i = 0; i < SIZE; i++) {

		for( j = 0; j < SIZE; j++){
			if (nums[i] == nums2[j])
                  duplicate = 1;
            } //end for loop
              if( i == 0)
                 duplicate = 0;

             if(duplicate == 0 )
                 nums2[i] = nums[i];

	       duplicate = 0; //reset to 0;
	} //end for loop

	puts("");//a new line

	puts("The nonduplicate values are");

	for(i = 0; i < SIZE; i++){
		if( nums2[i] != 0)
		printf("%d ", nums2[i]);
	}//end for loop
	
	puts(""); //a new line
	
	puts("The values of nums are");
	
	for( i = 0; i < SIZE; i++)
	     printf("%d ", nums[i] );
	
	puts(""); //new line
	
	puts("The values of num2 are: ");
	
	for(i = 0; i < SIZE; i++)
	    printf("%d ", nums2[i]);
	    
	puts("");//new line
	
	puts("Sorting the array");
	
	bSort(nums, SIZE);

	puts("Array after sorting");
	for( i = 0; i < SIZE; i++)
	     printf("%d ", nums[i]);
	
	//addone function that sorts the arrays from smallest to largest
	        //and then display that

	return 0;
}

void bSort(int a[], int size){
	
	int pass = 0;
	int k = 0;
	int hold = 0;
	
	for( pass = 1; pass < size; pass++){
		
		for ( k = 0; k < size -1; k++){
			if( a[k] > a[k + 1] ){
				hold = a[k];
				a[k] = a[k+1];
				a[k+1] = hold;
			}//end if block
		}//end for loop
	}//end for loop
	
}//end function bSort
