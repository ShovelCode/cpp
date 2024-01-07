//Christopher RAY
//Hackathon
//A queue implemented in C.

#include <stdio.h>
#include <stdlib.h>

//the self referential structure
struct queueNode{
  char data; //will hold single characters
  struct queueNode *nextPtr;
}; //end structure queueNode

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

//function prototypes
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
void instructions(void);

int main(void){
QueueNodePtr headPtr = NULL; //initialize headPtr.
QueueNodePtr tailPtr = NULL; //initialize tailPtr.
unsigned int choice; //user's menu choice
char item; //character input by user

instructions();
printf("%s", "? ");
scanf("%u", &choice);

//while user does not enter 3
while(choice != 3) {

  switch(choice){
   //enqueue value
   case 1:
    printf("%s","Enter a character: ");
    scanf("\n%c", &item);
    enqueue(&headPtr, &tailPtr, item);
    printQueue(headPtr);
    break;
  //dequeue the value
   case 2:
    //if queue is not empty
    if(!isEmpty(headPtr)){
        item = dequeue(&headPtr, &tailPtr);
        printf("%c has been dequeued.\n", item);
     }//end if
     printQueue(headPtr);
     break;
  }//end  switch


  printf("%s", "? ");
  scanf("%u", &choice);
}//end while

puts("End of run");
}//end main

//display program instructions to the user
void instructions(void){
  printf("Enter your choice:\n"
         "   1 to add an item to the queue\n"
         "   2 to remove anaitem from the queue\n"
         "   3 to end\n");
}//end function instructions

//insert a node in at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value){

  QueueNodePtr newPtr; //pointer to new node
  newPtr = malloc(sizeof(QueueNode));
  
  if(newPtr != NULL){ //checking if space is available
     newPtr->data = value;
     newPtr->nextPtr = NULL;

      //if empty, insert node at head
      if( isEmpty(*headPtr)){
          *headPtr = newPtr;
        }//end if
        else { 
               (*tailPtr)->nextPtr = newPtr;
          }//end else

       *tailPtr = newPtr;
     }//end  if
  else {
    printf("%c not inserted. No Memory available.\n",value);
   }//end else
}//end function enqueue

//remove node from queue head
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
  char value; //node value
  QueueNodePtr tempPtr; //temporary node pointer

  value = (*headPtr)->data;
  tempPtr = *headPtr;
  *headPtr = (*headPtr)->nextPtr;

  //if queue is empty
  if(*headPtr == NULL) {
     *tailPtr = NULL;
 }//end if

   free(tempPtr);
   return value;
}//end function dequeue

//return 1 if the queu is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr){
  return headPtr == NULL;
}// end function isEmpty

//print the queue
void printQueue(QueueNodePtr currentPtr){
  //if queue is empty
  if(currentPtr == NULL) {
     puts("Queue is empty.\n");
  }//end if
  else {
       puts("The queue is:" );
     
       while(currentPtr != NULL){
              printf("%c --> ", currentPtr->data);
              currentPtr = currentPtr->nextPtr;
            }//end while

       puts("NULL\n");
    }//end else
}//end function printQueue
