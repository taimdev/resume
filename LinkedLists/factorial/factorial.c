// selectEven.c
// 
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "list-factorial.h"


//return a list with 
//1 to x factorial
//factorial(3) would return a list with
// 1->2->6->X
//For x <= 0 just return an empty list
static link createNode (int value);
static void addToEnd(list l, link n);

list factorial (int x) {
   list factlist = malloc(sizeof(struct _list));
   factlist->head = NULL;
   link factnode;

   int counter = 1;
   int sum = 1;

     	while (counter <= x) {
   	    	sum = sum * counter ;
   	    	printf("sum is %d\n", sum);
        	factnode = createNode(sum);
        	addToEnd(factlist, factnode);
        	counter ++;
       }



   return factlist;
}

static link createNode (int value) {
	link curr = malloc(sizeof(node));
	curr->value = value;
	curr->next = NULL;

	return curr;
}

static void addToEnd(list l, link n) {
	link curr = l->head;

	if (curr == NULL) {
		l->head = n;
	} else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
}
