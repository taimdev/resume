#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "list-selectEven.h"
     
// given a list of integers, write a function which 
// finds all even integers and constructs
// a new list containing these even integers 
// The original list should remain unmodified.
// The new list should be returned by the function.
// So if the original list is 1->55->66->4->X, the function
// should return a list 66->4->X. 
// And if the original list is 1->3->7->X, the function
// should return an empty list.
//
// Constraints:
// don't delete any nodes (i.e. do not call free())
// the order of integers in the new list should be the same as the original
// the original list should remain unmodified
//

static list createList(void);
static link createNode(int val);     
static void addToEnd(list l, link n);


list selectEven (list sourceList) {
    list newList = createList();
    
    link newNode = NULL;
    link curr = sourceList->head;
     
    while(curr != NULL){
       if(curr->value %2 == 0){
           newNode = createNode(curr->value);
           addToEnd(newList,newNode);
       }
       curr = curr->next;
    }
    return newList;
}

static list createList(void){
    list l = malloc(sizeof(struct _list));
    l->head = NULL;
    return l;
}
static link createNode(int val){
    link n = malloc(sizeof(struct _node));
    n->value = val;
    n->next = NULL;
    return n;
}
static void addToEnd(list l, link n){
   link curr;
   if(l->head == NULL){
       l->head = n;
   } else {
       curr = l->head;
       while(curr->next != NULL){
            curr = curr->next;
       }
       curr->next = n;
   }
}
