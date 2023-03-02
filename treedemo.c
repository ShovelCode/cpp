//Christopher RAY
//Hackathon
//A tree made in C.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//the self referential structure
struct treeNode{
  struct treeNode *leftPtr; //pointer to left subtree
  int data; //a tree of int
  struct treeNode *rightPtr;
}; //end structure treeNode

typedef struct treeNode TreeNode; //synonym
typedef  TreeNode *TreeNodePtr;  //synonym

//function prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void  postOrder(TreeNodePtr treePtr);

int main(void){

  unsigned int i; //counter for 1 to 10 loop
  int item;
  TreeNodePtr rootPtr = NULL;

  srand(time(NULL));
  puts("The numbers being placed in the tree are:");

  //insert random values between 0 and 14 in the tree
  for(i = 1; i <=10; ++i) {
      item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
   }//end for

//traverse the tree preOrder
  puts("\n\nThe preOrder traversal is:");
  preOrder(rootPtr);

  //traverse the tree inOrder
  puts("\n\nThe inOrder traversal is:");
  inOrder(rootPtr);

  //traverse the tree postOrder
  puts("\n\nThe postOrder traversal is:");
  postOrder(rootPtr);

  puts("\n");
}//end main

//insert node into tree
void insertNode(TreeNodePtr *treePtr, int value){
  //if tree is empty
  if(*treePtr == NULL){
     *treePtr = malloc(sizeof(TreeNode));
     
     //if memory was allocated, then assign data
     if(*treePtr != NULL){
          (*treePtr)->data = value;
          (*treePtr)->leftPtr = NULL;
          (*treePtr)->rightPtr = NULL;
        }//end if
        else {
          printf("%d not inserted. No memory available.\n", value );
        }//end else
     }//end if
     else { //tree is not empty
         //data to inserrt is less than data in current node
         if( value  <   (* treePtr)->data) {
             insertNode( &((*treePtr)->leftPtr), value);
          }//end if

         //data to insert  is greater than data in current node
        else if(value > ( *treePtr)->data) {
               insertNode(&((*treePtr)->rightPtr), value);
            } //end else if
         else { //duplicate data value ignored
           printf("%s", "dup");
          }//end else
     }//end else
 }//end function insertNode

//begin inorder traversal of tree
void inOrder(TreeNodePtr treePtr){
//if tree is not empty, then traverse
  if(treePtr != NULL){
     inOrder(treePtr->leftPtr);
     printf("%3d", treePtr->data);
     inOrder(treePtr->rightPtr);
    }//end if
}//end function inOrder


//begin preorder traversal of tree
void preOrder(TreeNodePtr treePtr){
//if tree is not empty, then traverse
  if(treePtr != NULL){
     printf("%3d", treePtr->data);
     preOrder(treePtr->leftPtr);
     preOrder(treePtr->rightPtr);
    }//end if
}//end function preOrder

//begin postOrder traversal of tree
void postOrder(TreeNodePtr treePtr){
  //if tree is not empty, then traverse
   if(treePtr != NULL){
     postOrder(treePtr->leftPtr);
     postOrder(treePtr->rightPtr);
     printf("%3d", treePtr->data);
   }//end if
}//end function postOrder
