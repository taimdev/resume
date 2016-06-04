// selectEven.c
// 
     
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
     
#include "list-moveEven.h"

//THIS IS A VARIATION ON THE SELECT EVEN QUESTION
     
// given a list of integers, write a function which 
// finds all even integers 
// and moves them a new list 
// The original list should have only the odd values remaining
// The new list should be returned by the function.
// So if the original list is 1->2->55->66->4->X, the function
// should return a list 2->66->4->X. 
// the original list would be 1-55->X
// And if the original list is 1->3->7->X, the function
// should return an empty list and the original list would be unchanged.
//
// Constraints:
// don't delete any nodes (i.e. do not call free())
// the order of integers in the new list should be the same as the original
// the order of odd integers in the original list should be unchanged
// You should not malloc any new struct _node . 
//

    
static void addToEnd(list l, link n);


list selectEven (list sourceList) {
	list evenList = malloc(sizeof(struct _list));
	evenList->head = NULL;

	link curr = sourceList->head;
	link prev = NULL;
	int currvalue;


	while (curr != NULL) {
		currvalue = curr->value;
		if (currvalue % 2 == 0) {
			addToEnd(evenList, curr);
			if (prev == NULL) {
				sourceList->head = curr->next;
			} else {
				prev->next = curr->next;
			}

		} else {
			prev = curr;
		}

		curr = curr->next;
	}
	return evenList;
}

static void addToEnd(list l, link n) {
	n->next = NULL;
	link curr = l->head;

	if (l->head == NULL) {
		l->head = n;
	} else {
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
}

