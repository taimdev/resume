// Taimur Azhar z5116684
// 18/05/2016
// Core List Actities

// a concrete linked list

// list is a pointer to a struct - containing the head ptr
// 18 may 2014 tests expanded. includes tests on append to 
// explicitly detect non-null "next" in the appended node.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-core.h"

// simple unit tests on the list
 static void testList (void);

int main (int argc, char *argv[])  {
    printf ("Testing list3-core...\n");
    testList();
    printf ("All list3-core tests passed!  You are awesome\n");

	return EXIT_SUCCESS;
}

void showList(list listToPrint) {
	link curr = listToPrint->head;

	//assert(curr != NULL);

	while (curr != NULL) {
		//printf("The value is %d", curr->value);
		curr = curr->next;
	}
}

void frontInsert(list l, int item) {
	link curr = malloc(sizeof(node));
	curr->next = l->head;
	l->head = curr;
	curr->value = item;
}

int numItems(list l) {
	int length;
	link curr = l->head;

	//assert(curr != NULL);

	while (curr != NULL) {
		length++;
		curr = curr->next;
	}

	return length;
}

void append (list l, int value) {
	link final = malloc(sizeof(node));
	final->next = NULL;
	final->value = value;

	link curr = l->head;

	//assert(curr != NULL);

	while (curr->next != NULL) {
		curr = curr->next;
	}

	curr->next = final;
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
	int returnValue;
	int counter = 0;

	link curr = l->head;

	while (counter < position) {
		counter ++;
		curr = curr->next;
	}

	returnValue = curr->value;

	return returnValue;
}




static void testList (void) {

    // create empty lst
    list myList = malloc (sizeof (*myList));
    myList->head = NULL;
    // myList is a struct which has an element head which
    // points to the first node of the list aka the head


    // simple test on showlist and numItems
    showList (myList);
    assert (numItems (myList) == 0);

    // attach one node to the list
    link ptrToNewNode = malloc (sizeof (node));
    assert (ptrToNewNode != NULL); 
    ptrToNewNode->value = 1;
    ptrToNewNode->next = NULL;

    myList->head = ptrToNewNode;  

    // simple test on showlist and numItems
    showList (myList);
    assert (numItems (myList) == 1);

    // attach a second node to the list
    ptrToNewNode = malloc (sizeof (node));
    assert (ptrToNewNode != NULL);  

    ptrToNewNode->value = 2;
    ptrToNewNode->next = NULL;

    myList->head->next = ptrToNewNode;

    showList (myList);
    assert (numItems (myList) == 2);

    // insert a node containing 0 at te head, ie before 
    // the 1->2->X list, to produce 0->1->2->X

    frontInsert (myList, 0); 
    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->value == 0);
    assert (myList->head->next  != NULL);
    assert (myList->head->next->value == 1);

    showList (myList);
    assert (numItems (myList) == 3);

    // insert at end 
    append (myList, 4);

    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->next != NULL);
    assert (myList->head->next->next != NULL);
    assert (myList->head->next->next->next != NULL);
    assert (myList->head->next->next->next->value == 4);
    assert (myList->head->next->next->next->next  == NULL);

    showList (myList);
    assert (numItems (myList) == 4);

    // test lookup
    assert (lookup (myList,0)==0);
    assert (lookup (myList,1)==1);
    assert (lookup (myList,2)==2);
    assert (lookup (myList,3)==4);
   
}



