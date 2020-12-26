//Christopher Ray


#include <stdio.h>
#include <stddef.h>

#define SIZE 20

void bSort(int a[], int size);
void bSort2(char a[], int size);

int main(){

	unsigned int i           =   0;  //loop control
	unsigned int j           =   0;  //loop control
	int          duplicate   =   0;  //acts as a boolean value
	int          nums[SIZE]  = {0};  //20 integers initialized to 0
	int          nums2[SIZE] = {0};  //20 integers initialized to 0;
	char         alph[SIZE]  = {65}; //20 characters initialized to character #65
	char         alph2[SIZE] = {65}; //20 characters initialized to character #65

	puts("Enter 20 characters between a and z, no spaces");

	for(i = 0; i < SIZE; i++)
	    scanf("%c", &alph[i]);

	for(i = 0; i < SIZE; i++) {

		for( j = 0; j < SIZE; j++){
			if (alph[i] == alph2[j])
                  duplicate = 1;
            } //end for loop
              if( i == 0)
                 duplicate = 0;

             if(duplicate == 0 )
                 alph2[i] = alph[i];

	       duplicate = 0; //reset to 0;
	} //end for loop
	
	puts("");//a new line

	puts("The nonduplicate values are");

	for(i = 0; i < SIZE; i++){
		if( alph2[i] != '*')
		printf("%c ", alph2[i]);
	}//end for loop
	
	puts(""); //a new line
		
	puts("Sorting the array");
		
	bSort2(alph2, SIZE);

	puts("Array after sorting");
	for( i = 0; i < SIZE; i++){
	     printf("%c", alph2[i]);
	}//end for( i = 0
	
	puts("");//new line

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

void bSort2(char a[], int size){

	int pass = 0;
	int k = 0;
	char hold = '@';

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
