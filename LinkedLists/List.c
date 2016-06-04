//Written by Michael Simarta
//With the help of Bernice Chen
//list.c file that implements all functions declared in list.h
//implement the median() function here
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
 
typedef struct _node {
    int value;
    Node next;
} node;
 
typedef struct _list {
    Node head;
} list;
 
//when the median() function is complete,
//compile with testList.c, type
//"gcc -Wall -Werror -O -o test testList.c List.c"
//to run program, type
//"./test"
 
//TODO
//Read List.h to help you look at the hints
//find the median value
//given a list X
//(Empty List)
//then median (list);
//it will return 0 
 //
//given a list 1->X
//then median (list);
//it will return 1  
//
//given a list 0->1->2->X
//then median (list);
//it will return 1
//
//given a list 2->3->5->6->X
//then median (list);    
//it will return 4
//because the middle is the average of the 2 middlemost numbers
//(3+5)/2 = 4.
//We will not test where the average will lead to decimal places
//
//given a list 2->3->5->6->1000->X
//then median (list);
//it will return 5
int median(List l) {
    int median = 0;
    int counter = 0;
    int medindex = 0;
    int medcounter = 1;
    Node curr = l->head;  
    Node prev = NULL;  
    
    if (l->head == NULL) {
    
    } else {
        while (curr != NULL) {
            curr = curr->next;
            counter++;
        }
        //printf("The length is %d\n", counter);
        curr = l->head;
        
        
        if (counter % 2 != 0) {
            medindex = ((counter + 1) / 2);
            //printf("The index is %d\n", medindex);
            
            while (medcounter < medindex) {
                curr = curr->next;
                medcounter ++;
            }
            median = curr->value;
            //printf("The median is %d\n", median);

        } else {
            medindex = ((counter / 2) + 1);
            //printf("The index is %d\n", medindex);

            while (medcounter < medindex) {
                prev = curr;
                curr = curr->next;
                medcounter ++;     
            }
            //printf("The curr value is %d\n", curr->value);
            //printf("the prev value is %d\n", prev->value);
            
            median = ((curr->value + prev->value) / 2);  
            //printf("The median is %d\n", median);
        
        }
        
    
    
    }
    
    
    return median;
}
 
//returns a new list of length 0
List newList() {
   List l = malloc(sizeof(list));
   assert ( l!=NULL );
   l->head = NULL;
   return l;
}
 
//frees everything malloced for the list
void destroy(List l) {
   Node curNode = l->head;
   Node prevNode = NULL;
 
   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }
 
   free(l);
}
 
//appends a node of value to the end of the list
void append(List l, int value) {
   Node newNode = malloc(sizeof(node));
   newNode->value = value;
   newNode->next = NULL;
   Node curNode = l->head;
   if ( curNode==NULL ) {
      l->head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
}
 
//returns the int value of the node at index
//assumes input index is within range of the list's length
int getValue(List l, int index) {
 
   Node curNode = l->head;
   assert (curNode!=NULL);
   int counter = 0;
   while (counter<index) {
      curNode = curNode->next;
      counter++;
   }
   return curNode->value;
}
