//Christopher RAY
//Hackathon
//A singly-linked list in C.

#include <stdio.h>
#include <stdlib.h>

struct listNode {
  char data;
  struct listNode *nextPtr;
};//end structure listNode

typedef struct listNode ListNode; //synonym
typedef  ListNode *ListNodePtr; //synonym

//prototypes
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void){
  ListNodePtr startPtr = NULL; //initially there are no nodes
  unsigned int choice; //user's choice
  char item; //entered by user

  instructions();
  printf("%s", "? ");
  scanf("%u", &choice);

  while(choice != 3){ //3 is ending sentinel
   switch(choice){
    case 1:
      printf("%s", "Enter a character: ");
      scanf("\n%c", &item);
      insert(&startPtr, item);
      printList(startPtr);
      break;
   case 2:
     //if list is not empty
     if(!isEmpty(startPtr)){
       printf("%s", "Enter a character to be deleted: ");
       scanf("\n%c", &item);
       //if character is found, remove it
       if(delete(&startPtr, item)) {
          printf("%c deleted. \n", item);
          printList(startPtr);
       }// end if
       else {
          printf("%c not found.\n\n", item);
       }//end else
     }//end if
     else {
        puts("List is empty. \n");
     }//end else
     break;
   default:
     puts("Invalid choice.\n");
     instructions();
     break;
   }//end switch

  printf("%s", "? ");
  scanf("%u", &choice);
  }// end while

 puts("End of run." );
} //  end main

//display program instructions to user
void instructions(void){
  puts("Enter your choice:\n"
  "   1 to insert an element into the list.\n"
  "   2 to delete an element from the list.\n"
  "   3 to end.");
}//end function instructions


//insert a new value into the list in sorted order
void insert( ListNodePtr *sPtr, char value){
  ListNodePtr newPtr;
  ListNodePtr previousPtr;
  ListNodePtr currentPtr;

  newPtr = malloc(sizeof(ListNode));

  if( newPtr != NULL){//is space available
     newPtr->data = value;
     newPtr->nextPtr = NULL;
     
    previousPtr = NULL;
    currentPtr =*sPtr;

   //loop to find the correct location in the list
   while( currentPtr != NULL && value > currentPtr->data){
     previousPtr = currentPtr; //walk to...
     currentPtr = currentPtr->nextPtr; //... next node
   }//end while

  //insdert new node at beginning of list
  if( previousPtr == NULL) {
     newPtr->nextPtr = *sPtr;
     *sPtr = newPtr;
  }//end if
  else { //insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr; 
       }//end else
}//end if
  else {
         printf("%c not inserted. No memory available.\n", value);
       }//end else
}//end function insert


//delete a list element
char delete( ListNodePtr *sPtr, char value){

  ListNodePtr previousPtr;
  ListNodePtr currentPtr;
  ListNodePtr tempPtr;

  //delete first node
  if( value == (*sPtr)->data) {
      tempPtr = *sPtr;//hole onto node being removed
      *sPtr = (*sPtr)->nextPtr; //de-thread the node
      free(tempPtr);
      return value;
    }//end if
  else {
         previousPtr = *sPtr;
         currentPtr = (*sPtr)->nextPtr;

         //loop to find the correct locatio in the list
      while( currentPtr != NULL && currentPtr->data != value) {
             previousPtr = currentPtr; //walk too
             currentPtr = currentPtr->nextPtr; //..next node
      }//end while

      //delete node at currentPtr
      if( currentPtr != NULL) {
          tempPtr = currentPtr;
          previousPtr->nextPtr = currentPtr->nextPtr;
          free(tempPtr);
          return value;
        }// end if
     }//end else
     return '\0'; 
}//end function delete

//return 1 if the list is empty 0 otherwise
int isEmpty (ListNodePtr sPtr){
  return sPtr == NULL;
}//end function isEmpty

//print the list
void printList(ListNodePtr currentPtr){
  //if list is empty
  if( isEmpty(currentPtr)) {
       puts("List is empty.\n");
    }//end if
   else {
         puts("The list is:");
         
        while(currentPtr != NULL) {
              printf("%c --> ", currentPtr->data);
              currentPtr = currentPtr->nextPtr;
        }//end while

        puts(" NULL\n");
   }//end else
}//end function printList)
