/*
 *  reverseList.c
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by Taimur Azhar
 *  Share freely CC-BY-3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "reverseList.h"

static list insertFront (list reverseList, int value);


list reverseList (list inputList) {
	list reverseList = malloc(sizeof(*reverseList));
	reverseList->head = NULL;

	link curr = inputList->head;
	int storeVal;

	while (curr != NULL) {
		storeVal = curr->value;
		
		reverseList = insertFront(reverseList, storeVal);
		printf("Value is %d\n", reverseList->head->value);
		curr = curr->next;
	}
	//printList(reverseList);
	inputList = reverseList;

	return inputList;
}

static list insertFront (list reverseList, int value) {
	link store = reverseList->head;

	link currnode = malloc(sizeof(node));
	currnode->value = value;
	currnode->next = store;

	reverseList->head = currnode;

	return reverseList;
}